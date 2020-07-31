#pragma once

#include "Buffer.h"
#include <vector>

class VertexArray
{
private:
	GLuint id;
	std::vector<Buffer*> buffer;
public:
	VertexArray();
	~VertexArray();

	void addBuffer(Buffer* _buffer, GLuint index); //index coresponds to the location value of the shaders

	void bind() const;
	void unbind() const;
};

