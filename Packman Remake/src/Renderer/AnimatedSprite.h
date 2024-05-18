#pragma once
#include "Texture.h"
#include "SpriteSheet.h"
#include "../Entity/Entity.h"

class AnimatedSprite : Entity{
public:
	SpriteSheet* AnimationSpriteSheet;
	int SpriteIndex;
	AnimatedSprite(SpriteSheet* spriteSheet);
};