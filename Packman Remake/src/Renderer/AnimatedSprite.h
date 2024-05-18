#pragma once
#include "Texture.h"
class SpriteSheet {
public:
	Texture* SheetSprite;
	int SheetRows;
	int SheetColumns;
public:
	SpriteSheet() = delete;
	SpriteSheet(Texture* sprite, int sheetRows, int sheetColumns);
};

class AnimatedSprite {
public:
	SpriteSheet* AnimationSpriteSheet;
	int SpriteIndex;
	AnimatedSprite(SpriteSheet* spriteSheet);
};