#pragma once
#include <glad/glad.h>
#include <iostream>

class Texture {
private:
	unsigned int m_textureID;
public:
	Texture();
	static Texture* LoadTextureFromPath(std::string Path);
	void Use();
};