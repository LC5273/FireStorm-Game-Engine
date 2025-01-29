#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer():id(-1), nr_of_elements(-1) {}

IndexBuffer::IndexBuffer(GLuint* data, GLsizei nr_of_elements): nr_of_elements(nr_of_elements) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nr_of_elements * sizeof(GLuint), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::IndexBuffer(std::vector<GLuint> data): nr_of_elements(data.size()) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nr_of_elements * sizeof(GLuint), data.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::createIndexBuffer(GLuint* data, GLsizei nr_of_elements) {
	//GLuint id;
	glGenBuffers(1, &id);
	this->id = id;
	this->nr_of_elements = nr_of_elements;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nr_of_elements * sizeof(GLuint), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::bind() const noexcept {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}
void IndexBuffer::unbind() const noexcept {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

GLuint IndexBuffer::get_id() const noexcept {
	return id;
}
GLuint IndexBuffer::get_nr_of_elements() const noexcept {
	return nr_of_elements;
}