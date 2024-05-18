#pragma once
#include <vector>
#include "../Util.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "../Entity/Entity.h"

class Renderer {
public:
	static Renderer* Instance;
private:
	unsigned int m_quadFBO, m_quadEBO, m_quadVAO;
	static float s_quadVerticies[];
	static int s_quadIndices[];
	Shader* SpriteShader;
	Shader* AnimatedSpriteShader;

	std::vector<Sprite*> m_sprites;
	std::vector<AnimatedSprite*> m_animatedSprite;
public:
	Renderer();
	void Clear();
	void CleanAll();
	void Render();
	void AddSprite(Sprite* sprite);
	void AddAnimatedSprite(AnimatedSprite* animatedSprite);
private:
	void RenderSprites();
	void RenderAnimatedSprites();
	void RenderSprite(Sprite* sprite);
	void RenderAnimatedSprite(AnimatedSprite* animatedSprite);
};