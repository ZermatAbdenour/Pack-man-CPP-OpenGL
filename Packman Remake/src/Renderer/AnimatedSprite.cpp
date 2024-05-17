#include"AnimatedSprite.h"
#include "Renderer.h"

SpriteSheet::SpriteSheet(Sprite* sprite, int sheetRows, int sheetColumns) : SheetSprite(sprite), SheetRows(sheetRows), SheetColumns(sheetColumns) {}

AnimatedSprite::AnimatedSprite(SpriteSheet* spriteSheet) :AnimationSpriteSheet(spriteSheet), SpriteIndex(0) {
	Renderer::Instance->AddAnimatedSprite(this);
}