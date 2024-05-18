#pragma once
#include"Texture.h"

class SpriteSheet {
public:
	Texture* SourceImage;
	int SheetRows;
	int SheetColumns;
public:
	SpriteSheet() = delete;
	SpriteSheet(Texture* sprite, int sheetRows, int sheetColumns);
};