#include"AnimatedSprite.h"
#include "Renderer.h"

SpriteSheet::SpriteSheet(Texture* sprite, int sheetRows, int sheetColumns) : SourceImage(sprite), SheetRows(sheetRows), SheetColumns(sheetColumns) {}

AnimatedSprite::AnimatedSprite(SpriteSheet* spriteSheet) :AnimationSpriteSheet(spriteSheet), SpriteIndex(0) {
	Renderer::Instance->AddAnimatedSprite(this);
}