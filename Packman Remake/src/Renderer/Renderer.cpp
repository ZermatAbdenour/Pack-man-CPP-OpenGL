#include "Renderer.h"

Renderer* Renderer::Instance = nullptr;

float Renderer::s_quadVerticies[] = {
	//Position     //Texture Coord
	 0.5f,  0.5f,  1.0f, 1.0f,  // top right
	 0.5f, -0.5f,  1.0f,0.0f,   // bottom right
	-0.5f, -0.5f,  0.0f,0.0f,   // bottom left
	-0.5f,  0.5f,  0.0f,1.0f    // top left 
};

int Renderer::s_quadIndices[] = {
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};


Renderer::Renderer()
{
	//Set Renderer Instance
	Instance = this;

	//Create Quad Buffers
	glGenVertexArrays(1, &m_quadVAO);
	glBindVertexArray(m_quadVAO);

	glGenBuffers(1, &m_quadFBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_quadFBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(s_quadVerticies), s_quadVerticies, GL_STATIC_DRAW);
	
	glGenBuffers(1, &m_quadEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_quadEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(s_quadIndices), s_quadIndices, GL_STATIC_DRAW);
	
	//Position
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	//Texture Coord
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2* sizeof(float)));
	glEnableVertexAttribArray(1);

	//Create the Sprite Shader
	SpriteShader = new Shader("Sprite.vert", "Sprite.frag");
	//Create the Animated Sprite Shader
	AnimatedSpriteShader = new Shader("AnimatedSprite.vert", "AnimatedSprite.frag");
}

void Renderer::Clear()
{
	glClearColor(0.5f, 1, 0.6f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::CleanAll()
{
	m_sprites.clear();
	m_animatedSprite.clear();
}

void Renderer::Render()
{
	//Render Game Sprites
	//RenderSprites();
	//Render Animated Sprites
	RenderAnimatedSprites();
}

void Renderer::AddSprite(Sprite* sprite)
{
	m_sprites.push_back(sprite);
}

void Renderer::AddAnimatedSprite(AnimatedSprite* animatedSprite)
{
	m_animatedSprite.push_back(animatedSprite);
}

void Renderer::RenderSprites()
{
	SpriteShader->Use();
	for (Sprite* sprite : m_sprites) {
		RenderSprite(sprite);
	}
}

void Renderer::RenderAnimatedSprites() {
	AnimatedSpriteShader->Use();
	for (AnimatedSprite* asprite : m_animatedSprite) {
		RenderAnimatedSprite(asprite);
	}
}

void Renderer::RenderSprite(Sprite* sprite)
{
	//Use Sprite Shader
	glUniform1i(glGetUniformLocation(SpriteShader->ID, "u_texture"), 0);
	//Use Sprite Texture
	sprite->SourceImage->Use();
	//Render Sprite
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);
}

void Renderer::RenderAnimatedSprite(AnimatedSprite* animatedSprite)
{
	//Use Sprite Shader
	glUniform1i(glGetUniformLocation(AnimatedSpriteShader->ID, "u_texture"), 0);
	glUniform1f(glGetUniformLocation(AnimatedSpriteShader->ID, "u_spriteColumns"), animatedSprite->AnimationSpriteSheet->SheetColumns);

	glUniform1f(glGetUniformLocation(AnimatedSpriteShader->ID, "u_spriteRows"), animatedSprite->AnimationSpriteSheet->SheetRows);
	glUniform1ui(glGetUniformLocation(AnimatedSpriteShader->ID, "u_spriteIndex"), animatedSprite->SpriteIndex);
	//Use Sprite Texture
	animatedSprite->AnimationSpriteSheet->SourceImage->Use();
	//Render Sprite
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}