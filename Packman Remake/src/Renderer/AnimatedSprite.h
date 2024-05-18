#pragma once
#include "Texture.h"
#include "SpriteSheet.h"
#include "../Entity/Entity.h"
#include "IRanderable.h"
#include "Shader.h"

class AnimatedSprite : public Entity, public IRenderable{
public:
	SpriteSheet* AnimationSpriteSheet;
	int SpriteIndex;
	Shader* AnimatedSpriteShader = new Shader("AnimatedSprite.vert", "AnimatedSprite.frag");
public:
	AnimatedSprite(SpriteSheet* spriteSheet);
	void Render();
};