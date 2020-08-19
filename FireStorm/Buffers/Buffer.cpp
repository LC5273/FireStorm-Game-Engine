#include "Buffer.h"

Buffer::Buffer(GLfloat* data, GLsizei count, GLuint nr_of_elements): nr_of_elements(nr_of_elements) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::update(GLfloat* data, GLsizei count) {
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, id);
}
void Buffer::unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLuint Buffer::get_id() const {
	return id;
}
GLuint Buffer::get_nr_of_elements() const {
	return nr_of_elements;
}