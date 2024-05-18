#pragma once
#include <glad/glad.h>

class Shader {
public:
	unsigned int ID;
public: 
	Shader() = delete;
	Shader(const char * vertexShader,const char*fragmentShader);
	void Use();
};