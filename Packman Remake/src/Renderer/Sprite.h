#pragma once
#include <glad/glad.h>
#include <iostream>

class Sprite {
private:
	unsigned int m_textureID;
public:
	Sprite();
	static Sprite* LoadSpriteFromPath(std::string Path);
	void Use();
};