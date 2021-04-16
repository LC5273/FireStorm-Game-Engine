#pragma once

#include <string>

#include "GL\glew.h"
#include "GLFW\glfw3.h"

class Texture
{
private:
	unsigned int id;
	int width, height, bits_per_pixel;
	std::string filepath;
	unsigned char *buffer;
public:
	Texture();
	Texture(const std::string& _filepath);

	void getTexture(std::string&& _filepath);

	void bind(unsigned int slot = 0) const;
	void unbind() const;

	inline unsigned int getHeight() const noexcept { return height; };
	inline unsigned int getWidth() const noexcept { return width; };

	//~Texture();
};

