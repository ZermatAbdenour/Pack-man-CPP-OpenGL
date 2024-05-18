#include "Sprite.h"
#include "Renderer.h"

Sprite::Sprite()
{
	//add sprite to the renderer
	Renderer::Instance->AddRenderable(this);
}

Sprite::Sprite(Texture* sourceImage)
{
	SourceImage = sourceImage;
	//add sprite to the renderer
	Renderer::Instance->AddRenderable(this);
}

void Sprite::Render()
{
	//Use Sprite Shader
	SpriteShader->Use();
	glUniform1i(glGetUniformLocation(SpriteShader->ID, "u_texture"), 0);
	//Use Sprite Texture
	SourceImage->Use();
	//Render Sprite
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}