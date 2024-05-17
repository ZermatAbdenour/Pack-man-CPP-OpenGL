#pragma once
#include "Sprite.h"
#include <vector>
class Renderer {
public:
	static Renderer* Instance;
	void AddSprite(Sprite* sprite);
private:
	unsigned int m_quadFBO, m_quadEBO, m_quadVAO, shaderID;
	static float s_quadVerticies[];
	static int s_quadIndices[];

	std::vector<Sprite*> m_sprites;
public:
	Renderer();
	void Clear();
	void Render();
private:
	void RenderSprites();
	void RenderSprite(Sprite* sprite);
};