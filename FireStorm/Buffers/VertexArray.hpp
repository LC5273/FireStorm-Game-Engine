#pragma once

#include "Buffer.hpp"
#include <vector>

class VertexArray
{
private:
	GLuint id;
	//std::vector<Buffer*> buffer;
public:
	VertexArray();
	//VertexArray(const VertexArray& vao);

	//VertexArray& operator=(const VertexArray& vao);

	void addBuffer(Buffer* _buffer, GLuint index); //index coresponds to the location value of the shaders

	GLuint getID() const noexcept;

	void bind() const;
	void unbind() const;

	//~VertexArray();
};

