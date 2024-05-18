#include "Sprite.h"
#include "Renderer.h"

Sprite::Sprite()
{
	//add sprite to the renderer
	Renderer::Instance->AddSprite(this);
}

Sprite::Sprite(Texture* sourceImage)
{
	SourceImage = sourceImage;
	//add sprite to the renderer
	Renderer::Instance->AddSprite(this);
}
