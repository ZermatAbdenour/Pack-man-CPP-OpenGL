#include "Renderer.h"
#include "../Util.h"
float Renderer::s_quadVerticies[] = {

	//Pos     
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
	glGenVertexArrays(1, &m_quadVAO);
	glBindVertexArray(m_quadVAO);

	glGenBuffers(1, &m_quadFBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_quadFBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(s_quadVerticies), s_quadVerticies, GL_STATIC_DRAW);
	
	glGenBuffers(1, &m_quadEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_quadEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(s_quadIndices), s_quadIndices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Create and compile the vertex shader
	unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	const char* a = ReadShaderFromFile("");
	glShaderSource(vertexShaderID, 1,&a, NULL);
	glCompileShader(vertexShaderID);

	int  success;
	char infoLog[512];
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//Create and Compile fragment shader
	unsigned int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &vertexShaderSource, NULL);
	glCompileShader(fragmentShaderID);

	int  success;
	char infoLog[512];
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//Create Shader Program
	shaderID = glCreateProgram();
	//Attach the vertex shader to the shader program
	glAttachShader(shaderID, fragmentShaderID);
	//Attach the vertex shader to the shader program
	glAttachShader(shaderID, vertexShaderID);
	glLinkProgram(shaderID);

	// check for linking errors
	glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

void Renderer::RenderSprite(Sprite sprite)
{
	
}