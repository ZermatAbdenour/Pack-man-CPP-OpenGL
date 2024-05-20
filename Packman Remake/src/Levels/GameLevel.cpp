#include "GameLevel.h"
#include "../Util.h"
#include "../Renderer/Sprite.h"
#include "../Renderer/AnimatedSprite.h"
#include "../Renderer/AnimatedSprite.h"

void GameLevel::Load()
{
    Texture* sprite = Texture::LoadTextureFromPath(GetImagePath("maze.png"));
    SpriteSheet* spriteSheet = new SpriteSheet(sprite, 10, 10);
    Sprite* animatedSprite = new Sprite(sprite);
}

void GameLevel::Update()
{
    
}