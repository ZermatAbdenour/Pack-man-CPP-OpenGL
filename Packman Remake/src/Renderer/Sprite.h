#pragma once
#include "Texture.h"
#include "../Entity/Entity.h"
#include "Shader.h"
#include "IRanderable.h"

class Sprite:public Entity,public IRenderable{
public:
	Texture* SourceImage;
	Shader* SpriteShader = new Shader("Sprite.vert", "Sprite.frag");;
public:	
	Sprite();
	Sprite(Texture* sourceImage);
	void Render();
};