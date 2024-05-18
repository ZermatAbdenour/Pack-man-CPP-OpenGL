#include"AnimatedSprite.h"
#include "Renderer.h"


AnimatedSprite::AnimatedSprite(SpriteSheet* spriteSheet) :AnimationSpriteSheet(spriteSheet), SpriteIndex(0) {
	Renderer::Instance->AddRenderable(this);
}

void AnimatedSprite::Render()
{
	//Use Sprite Shader
	AnimatedSpriteShader->Use();
	glUniform1i(glGetUniformLocation(AnimatedSpriteShader->ID, "u_texture"), 0);
	glUniform1f(glGetUniformLocation(AnimatedSpriteShader->ID, "u_spriteColumns"),AnimationSpriteSheet->SheetColumns);

	glUniform1f(glGetUniformLocation(AnimatedSpriteShader->ID, "u_spriteRows"), AnimationSpriteSheet->SheetRows);
	glUniform1ui(glGetUniformLocation(AnimatedSpriteShader->ID, "u_spriteIndex"),SpriteIndex);
	//Use Sprite Texture
	AnimationSpriteSheet->SourceImage->Use();
	//Render Sprite
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}