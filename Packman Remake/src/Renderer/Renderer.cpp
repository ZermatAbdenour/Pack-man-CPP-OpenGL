#include "Renderer.h"
#include <glm/gtc/type_ptr.hpp>

Renderer* Renderer::Instance = nullptr;

float Renderer::s_quadVerticies[] = {
	//Position     //Texture Coord
	 0.5f,  0.5f,  1.0f, 1.0f,  // top right
	 0.5f, -0.5f,  1.0f,0.0f,   // bottom right
	-0.5f, -0.5f,  0.0f,0.0f,   // bottom left
	-0.5f,  0.5f,  0.0f,1.0f    // top left 
};

int Renderer::s_quadIndices[] = {
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};


Renderer::Renderer()
{
	//Set Renderer Instance
	Instance = this;

	//Create Quad Buffers
	glGenVertexArrays(1, &m_quadVAO);
	glBindVertexArray(m_quadVAO);

	glGenBuffers(1, &m_quadFBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_quadFBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(s_quadVerticies), s_quadVerticies, GL_STATIC_DRAW);
	
	glGenBuffers(1, &m_quadEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_quadEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(s_quadIndices), s_quadIndices, GL_STATIC_DRAW);
	
	//Position
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	//Texture Coord
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2* sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Renderer::Clear()
{
	glClearColor(0.5f, 1, 0.6f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::CleanAll()
{
	m_renderables.clear();
}

void Renderer::Render()
{
	for (IRenderable* renderable : m_renderables) {
		renderable->Render();
	}
}

void Renderer::AddRenderable(IRenderable* renderable) {
	m_renderables.push_back(renderable);
}

glm::mat4 Renderer::GetProjectionMartrix()
{
	float aspectRatio = (float)ScreenWidth / ScreenHeight;
	float orthoLeft = -aspectRatio;
	float orthoRight = aspectRatio;
	float orthoBottom = -1.0f;
	float orthoTop = 1.0f;

	return glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop, 0.0f, 1.0f);
}