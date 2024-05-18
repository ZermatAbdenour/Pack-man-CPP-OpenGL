#pragma once
#include "Texture.h"

class Sprite {
public:
	Texture* SourceImage;
public:	
	Sprite();
	Sprite(Texture* sourceImage);
};