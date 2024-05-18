#pragma once
#include "Texture.h"
#include "../Entity/Entity.h"
class Sprite : Entity{
public:
	Texture* SourceImage;
public:	
	Sprite();
	Sprite(Texture* sourceImage);
};