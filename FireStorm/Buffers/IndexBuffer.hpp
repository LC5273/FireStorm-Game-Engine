#pragma once

#include "GL\glew.h"
#include "GLFW\glfw3.h"

class IndexBuffer
{
private:
	GLuint id;
	GLuint nr_of_elements;
public:
	IndexBuffer();
	IndexBuffer(GLuint* data, GLsizei nr_of_elements);

	void create_IndexBuffer(GLuint* data, GLsizei nr_of_elements);

	void bind() const noexcept;
	void unbind() const noexcept;

	GLuint get_id() const noexcept;
	GLuint get_nr_of_elements() const noexcept;
};