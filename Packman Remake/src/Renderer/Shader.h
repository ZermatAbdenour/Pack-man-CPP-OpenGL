#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader {
public:
	unsigned int ID;
public: 
	Shader() = delete;
	Shader(const char * vertexShader,const char*fragmentShader);

	void SetInt(const char* name, int value);
	void SetUnsignedInt(const char* name, unsigned int value);
	void SetFloat(const char* name, float value);
	void SetMat4(const char* name, glm::mat4 value);
	void Use();
};