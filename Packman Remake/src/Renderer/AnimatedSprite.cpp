#include"AnimatedSprite.h"
#include "Renderer.h"


AnimatedSprite::AnimatedSprite(SpriteSheet* spriteSheet) :AnimationSpriteSheet(spriteSheet), SpriteIndex(0) {
	Renderer::Instance->AddRenderable(this);
	AnimationTimer = Time::Timer(FrameTime);
}

void AnimatedSprite::Render()
{
	//Update Animation Frame
	if (AnimationTimer.IsEnded())
	{
		int spritesCount = AnimationSpriteSheet->SheetColumns * AnimationSpriteSheet->SheetRows;
		if (Loop) {
			SpriteIndex = SpriteIndex >= spritesCount-1 ? 0 : SpriteIndex + 1;
		}
		else {
			SpriteIndex = SpriteIndex >= spritesCount-1 ? spritesCount - 1 : SpriteIndex + 1;
		}
		AnimationTimer.Reset();
	}

	//Use Sprite Shader
	AnimatedSpriteShader->Use();
	glUniform1i(glGetUniformLocation(AnimatedSpriteShader->ID, "u_texture"), 0);
	glUniform1f(glGetUniformLocation(AnimatedSpriteShader->ID, "u_spriteColumns"),AnimationSpriteSheet->SheetColumns);

	glUniform1f(glGetUniformLocation(AnimatedSpriteShader->ID, "u_spriteRows"), AnimationSpriteSheet->SheetRows);
	glUniform1ui(glGetUniformLocation(AnimatedSpriteShader->ID, "u_spriteIndex"),SpriteIndex);
	//update Transformation Matrices
	AnimatedSpriteShader->SetMat4("u_projection", Renderer::Instance->GetProjectionMartrix());
	AnimatedSpriteShader->SetMat4("u_model", GetModel());

	//Use Sprite Texture
	AnimationSpriteSheet->SourceImage->Use();
	//Render Sprite
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}