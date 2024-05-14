#include "Renderer.h"

float Renderer::s_quadVerticies[] = {
	-1,1,
	1,1,
	-1,-1,
	1,-1
};

int Renderer::s_quadIndices[] = {
	1,2,4,
	2,3,4
};

Renderer::Renderer()
{
	//Create Quad Buffers

	glGenBuffers(1, &m_quadFBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_quadFBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(s_quadVerticies), s_quadVerticies, GL_STATIC_DRAW);
	
	glGenBuffers(1, &m_quadEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_quadEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(s_quadIndices), s_quadIndices, GL_STATIC_DRAW);
}

void Renderer::RenderSprite(Sprite sprite)
{
	
}