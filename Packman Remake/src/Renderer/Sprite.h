#pragma once
#include <Stb/stb_image.h>
#include <glad/glad.h>
#include <iostream>

class Sprite {
private:
	unsigned int m_textureID;
public:
	Sprite();
	static Sprite* LoadSpriteFromPath(char* Path);
	void Use();
};