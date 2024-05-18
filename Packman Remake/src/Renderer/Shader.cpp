#include "Shader.h"
#include "../Util.h"

Shader::Shader(const char* vertexShader, const char* fragmentShader)
{
	//Create and compile the vertex shader
	unsigned int vertexID = glCreateShader(GL_VERTEX_SHADER);
	std::string vertexShaderContent = ReadShaderFromFile(GetShaderPath(vertexShader));
	const char* vertexShaderCode = vertexShaderContent.c_str();
	glShaderSource(vertexID, 1, &vertexShaderCode, NULL);
	glCompileShader(vertexID);

	int  success;
	char infoLog[512];
	glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//Create and Compile fragment shader
	unsigned int fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	std::string fragmentShaderContent = ReadShaderFromFile(GetShaderPath(fragmentShader));
	const char* fragmentShaderCode = fragmentShaderContent.c_str();
	glShaderSource(fragmentID, 1, &fragmentShaderCode, NULL);
	glCompileShader(fragmentID);


	glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	//Create Shader Program
	ID = glCreateProgram();
	//Attach the vertex shader to the shader program
	glAttachShader(ID, fragmentID);
	//Attach the vertex shader to the shader program
	glAttachShader(ID, vertexID);
	glLinkProgram(ID);

	// check for linking errors
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
}

void Shader::Use()
{
	glUseProgram(ID);
}