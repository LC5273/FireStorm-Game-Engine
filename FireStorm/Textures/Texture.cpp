#include "../vendor/stb_image/stb_image.h"
#include "Texture.hpp"

Texture::Texture(const std::string& _filepath) {

	stbi_set_flip_vertically_on_load(1);

	buffer = stbi_load(_filepath.c_str(), &width, &height, &bits_per_pixel, 4);

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (buffer)
		stbi_image_free(buffer);
}

void Texture::bind(unsigned int slot) const {
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind() const {
	glBindTexture(GL_TEXTURE_2D, 0);
}
/*
Texture::~Texture() {
	delete[] buffer;
}
*/

