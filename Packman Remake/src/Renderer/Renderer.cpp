#include "Renderer.h"


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

void Renderer::AddSprite(Sprite* sprite)
{
	m_sprites.push_back(sprite);
}

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

	//Create and compile the vertex shader
	unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	std::string vertexShaderContent = ReadShaderFromFile(GetShaderPath("VertexShader.vert"));
	const char* vertexShaderCode = vertexShaderContent.c_str();
	glShaderSource(vertexShaderID, 1,&vertexShaderCode, NULL);
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
	std::string fragmentShaderContent = ReadShaderFromFile(GetShaderPath("FragmentShader.frag"));
	const char* fragmentShaderCode = fragmentShaderContent.c_str();
	glShaderSource(fragmentShaderID, 1, &fragmentShaderCode, NULL);
	glCompileShader(fragmentShaderID);


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

void Renderer::Clear()
{
	glClearColor(0.5f, 1, 0.6f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Render()
{
	//Render Game Sprites
	RenderSprites();
}

void Renderer::RenderSprites()
{
	for (Sprite* sprite : m_sprites) {
		RenderSprite(sprite);
	}
}

void Renderer::RenderSprite(Sprite* sprite)
{
	//Use Sprite Shader
	glUseProgram(shaderID);
	glUniform1i(glGetUniformLocation(shaderID, "u_texture"), 0);
	//Use Sprite Texture
	sprite->Use();
	//RenderSprite
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);
}