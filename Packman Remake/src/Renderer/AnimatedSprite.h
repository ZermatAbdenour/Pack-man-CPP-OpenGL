#pragma once
#include "Texture.h"
#include "SpriteSheet.h"
#include "../Entity/Transform.h"
#include "IRanderable.h"
#include "Shader.h"
#include "../Engine/Time.h"

class AnimatedSprite : public Transform, public IRenderable{
public:
	SpriteSheet* AnimationSpriteSheet;
	int SpriteIndex;
	float FrameTime = 1;
	bool Loop = false;
	Shader* AnimatedSpriteShader = new Shader("AnimatedSprite.vert", "AnimatedSprite.frag");
private:
	Time::Timer AnimationTimer;
public:
	AnimatedSprite(SpriteSheet* spriteSheet);
	void Render();
};