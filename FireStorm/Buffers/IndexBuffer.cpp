#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer(GLuint* data, GLsizei nr_of_elements): nr_of_elements(nr_of_elements) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nr_of_elements * sizeof(GLuint), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}
void IndexBuffer::unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

GLuint IndexBuffer::get_id() const {
	return id;
}
GLuint IndexBuffer::get_nr_of_elements() const {
	return nr_of_elements;
}