#pragma once
#include <vector>
#include "../Util.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Shader.h"
#include "IRanderable.h"
#include "Renderer.h"

class Renderer {
public:
	static Renderer* Instance;
private:
	unsigned int m_quadFBO, m_quadEBO, m_quadVAO;
	static float s_quadVerticies[];
	static int s_quadIndices[];

	std::vector<IRenderable*> m_renderables;
public:
	Renderer();
	void Clear();
	void CleanAll();
	void Render();
	void AddRenderable(IRenderable* renderable);
};