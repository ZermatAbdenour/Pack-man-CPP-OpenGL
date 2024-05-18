#pragma once
#include <glad/glad.h>
#include <iostream>

class Texture {
private:
	unsigned int m_textureID;
	int Width, Height;
public:
	Texture();
	static Texture* LoadTextureFromPath(std::string Path);
	void Use();
};