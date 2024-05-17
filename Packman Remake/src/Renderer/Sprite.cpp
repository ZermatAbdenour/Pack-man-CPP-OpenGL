#include "Sprite.h"
#define STB_IMAGE_IMPLEMENTATION
#include <Stb/stb_image.h>
#include "Renderer.h"
Sprite::Sprite()
{
	//add sprite to the renderer
	Renderer::Instance->AddSprite(this);
}

Sprite* Sprite::LoadSpriteFromPath(char* Path){
	Sprite* sprite = new Sprite();

	//Load the Image using STBImage
	int width, height, nrChannels;
	unsigned char* data = stbi_load(Path, &width, &height, &nrChannels, 0);

	//Setting The Warping/Filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data) {
		//Generate the Texture and set the texture data
		glGenTextures(1, &sprite->m_textureID);
		glBindTexture(GL_TEXTURE_2D, sprite->m_textureID);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(sprite->m_textureID);
	}
	else {
		std::cout << "Error::Failed to load Image From Path" << std::endl;
	}
	stbi_image_free(data);

	return sprite;
}

void Sprite::Use()
{
	glBindTexture(GL_TEXTURE_2D,m_textureID);
}