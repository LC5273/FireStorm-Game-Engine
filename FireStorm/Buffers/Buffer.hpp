#pragma once

#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <utility>

class Buffer
{
private:
	GLuint id;
	GLuint nr_of_elements;
public:
	Buffer();
	Buffer(GLfloat* data, GLsizei count, GLuint nr_of_elements);
	Buffer(GLuint id, GLuint nr_of_elements);
	Buffer(const Buffer& buffer);
	Buffer(Buffer&& buffer) noexcept;

	Buffer&& forward(Buffer& buffer) noexcept;

	Buffer& operator=(const Buffer&);

	void update(GLfloat* data, GLsizei count, GLuint nr_of_elements);

	void bind() const;
	void unbind() const;

	GLuint get_id() const noexcept;
	GLuint get_nr_of_elements() const noexcept;
};