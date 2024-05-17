#pragma once
#include "Sprite.h"
class SpriteSheet {
public:
	Sprite* SheetSprite;
	int SheetRows;
	int SheetColumns;
public:
	SpriteSheet() = delete;
	SpriteSheet(Sprite* sprite, int sheetRows, int sheetColumns);
};

class AnimatedSprite {
public:
	SpriteSheet* AnimationSpriteSheet;
	int SpriteIndex;
	AnimatedSprite(SpriteSheet* spriteSheet);
};