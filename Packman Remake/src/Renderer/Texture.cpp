#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <Stb/stb_image.h>
#include "Renderer.h"
Texture::Texture()
{
}

Texture* Texture::LoadTextureFromPath(std::string Path){
	Texture* texture = new Texture();

	//Load the Image using STBImage
	stbi_set_flip_vertically_on_load(true);
	int nrChannels;
	unsigned char* data = stbi_load(Path.c_str(), &texture->Width, &texture->Height, &nrChannels, 0);
	if (data) {
		//Generate the Texture and set the texture data
		glGenTextures(1, &texture->m_textureID);
		glBindTexture(GL_TEXTURE_2D, texture->m_textureID);

		//Setting The Warping/Filtering options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		
		GLenum format = 0;
		if (nrChannels == 1)
			format = GL_RED;
		else if (nrChannels == 3)
			format = GL_RGB;
		else if (nrChannels == 4)
			format = GL_RGBA;
		glTexImage2D(GL_TEXTURE_2D, 0, format, texture->Width, texture->Height, 0, format, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Error::Failed to load Image From Path" << std::endl;
	}
	stbi_image_free(data);

	return texture;
}

void Texture::Use()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,m_textureID);
}