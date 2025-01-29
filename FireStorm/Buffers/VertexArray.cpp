#include "VertexArray.hpp"

VertexArray::VertexArray() {
	glGenVertexArrays(1, &id);
}
/*
VertexArray::VertexArray(const VertexArray& vao) {
	this->id = vao.getID();
}

VertexArray& VertexArray::operator=(const VertexArray& vao) {
	this->id = vao.getID();

	//vector
	return *this;
}
*/

void VertexArray::addBuffer(Buffer* buffer, GLuint index) {
	this->bind();
	buffer->bind();

	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, buffer->get_nr_of_elements(), GL_FLOAT, GL_FALSE, 0, 0);

	buffer->unbind();
	this->unbind();
}

GLuint VertexArray::getID() const noexcept {
	return id;
}

void VertexArray::bind() const {
	glBindVertexArray(id);
}

void VertexArray::unbind() const {
	glBindVertexArray(0);
}
/*
VertexArray::~VertexArray() {
	for (int i = 0; i < buffer.size(); ++i)
		delete buffer[i];
}
*/