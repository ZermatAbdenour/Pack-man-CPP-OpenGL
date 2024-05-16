#pragma once
#include "Sprite.h"
class Renderer {
public:
	Renderer();
	void RenderSprite(Sprite sprite);
private:
	unsigned int m_quadFBO, m_quadEBO, m_quadVAO,shaderID;
	static float s_quadVerticies[];
	static int s_quadIndices[];
};