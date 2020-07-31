#pragma once

#include "GL\glew.h"
#include "GLFW\glfw3.h"

class IndexBuffer
{
private:
	GLuint id;
	GLuint nr_of_elements;
public:
	IndexBuffer(GLuint* data, GLsizei nr_of_elements);

	void bind() const;
	void unbind() const;

	GLuint get_id() const;
	GLuint get_nr_of_elements() const;
};