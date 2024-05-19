#pragma once
#include "Texture.h"
#include "../Entity/Transform.h"
#include "Shader.h"
#include "IRanderable.h"

class Sprite:public Transform,public IRenderable{
public:
	Texture* SourceImage;
	Shader* SpriteShader = new Shader("Sprite.vert", "Sprite.frag");;
public:	
	Sprite();
	Sprite(Texture* sourceImage);
	void Render();
};