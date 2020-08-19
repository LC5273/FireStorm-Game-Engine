#pragma once

#include <string>

#include "GL\glew.h"
#include "GLFW\glfw3.h"


class Texture
{
private:
	unsigned int id;
	int width, height, bits_per_pixel;
	const std::string filepath;
	unsigned char* buffer;
public:
	Texture(const std::string& _filepath);

	void bind(unsigned int slot = 0) const;
	void unbind() const;

	inline unsigned int getHeight() const { return height; };
	inline unsigned int getWidth() const { return width; };

	//~Texture();
};

