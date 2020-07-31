#include "VertexArray.h"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &id);
}

VertexArray::~VertexArray() {
	for (int i = 0; i < buffer.size(); ++i)
		delete buffer[i];
}

void VertexArray::addBuffer(Buffer* _buffer, GLuint index) {
	this->bind();
	_buffer->bind();

	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, _buffer->get_nr_of_elements(), GL_FLOAT, GL_FALSE, 0, 0);

	_buffer->unbind();
	this->unbind();
}

void VertexArray::bind() const {
	glBindVertexArray(id);
}

void VertexArray::unbind() const {
	glBindVertexArray(0);
}