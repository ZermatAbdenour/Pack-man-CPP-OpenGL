#pragma once
#include <vector>
#include "../Util.h"
#include "Sprite.h"
#include "AnimatedSprite.h"

class Renderer {
public:
	static Renderer* Instance;
	void AddSprite(Sprite* sprite);
	void AddAnimatedSprite(AnimatedSprite* animatedSprite);
private:
	unsigned int m_quadFBO, m_quadEBO, m_quadVAO, shaderID;
	static float s_quadVerticies[];
	static int s_quadIndices[];

	std::vector<Sprite*> m_sprites;
	std::vector<AnimatedSprite*> m_animatedSprite;
public:
	Renderer();
	void Clear();
	void Render();
private:
	void RenderSprites();
	void RenderAnimatedSprites();
	void RenderSprite(Sprite* sprite);
	void RenderAnimatedSprite(AnimatedSprite* animatedSprite);
};