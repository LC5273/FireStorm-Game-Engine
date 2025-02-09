#include "../vendor/stb_image/stb_image.h"
#include "Texture.hpp"

Texture::Texture():width(0), height(0), bits_per_pixel(0) {
	buffer = nullptr;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
}

Texture::Texture(const std::string& _filepath) {

	stbi_set_flip_vertically_on_load(1);

	buffer = stbi_load(_filepath.c_str(), &width, &height, &bits_per_pixel, 4);

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (buffer)
		stbi_image_free(buffer);
}

Texture& Texture::operator=(const Texture& t) {
	this->id = t.id;
	this->width = t.width;
	this->height = t.height;
	this->bits_per_pixel = t.bits_per_pixel;
	this->filepath = t.filepath;
	if(t.buffer == nullptr)
		this->buffer = nullptr;
	else {
		this->buffer = new unsigned char[sizeof(t.buffer)];
		//strcpy((char*)this->buffer, (const char*)t.buffer);
		this->buffer = t.buffer;
	}
	
	return *this;
}

void Texture::getTexture(const std::string& _filepath) {
	stbi_set_flip_vertically_on_load(1);

	buffer = stbi_load(_filepath.c_str(), &width, &height, &bits_per_pixel, 4);

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

