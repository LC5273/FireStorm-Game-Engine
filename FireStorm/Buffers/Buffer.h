#pragma once

#include "GL\glew.h"
#include "GLFW\glfw3.h"

class Buffer
{
private:
	GLuint id;
	GLuint nr_of_elements;
public:
	Buffer(GLfloat* data, GLsizei count, GLuint nr_of_elements);

	void bind() const;
	void unbind() const;

	GLuint get_id() const;
	GLuint get_nr_of_elements() const;
};