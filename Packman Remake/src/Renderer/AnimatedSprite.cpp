#include"AnimatedSprite.h"
#include "Renderer.h"


AnimatedSprite::AnimatedSprite(SpriteSheet* spriteSheet) :AnimationSpriteSheet(spriteSheet), SpriteIndex(0) {
	Renderer::Instance->AddAnimatedSprite(this);
}