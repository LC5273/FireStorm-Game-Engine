#include "Buffer.hpp"

Buffer::Buffer():nr_of_elements(0) {
	glGenBuffers(1, &id);
}
Buffer::Buffer(GLfloat* data, GLsizei count, GLuint nr_of_elements): nr_of_elements(nr_of_elements) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Buffer::Buffer(GLuint id, GLuint nr_of_elements) : nr_of_elements(nr_of_elements) {
	this->id = id;
}

Buffer::Buffer(const Buffer& buffer): id(buffer.id), nr_of_elements(buffer.nr_of_elements) {}

Buffer::Buffer(Buffer&& buffer) noexcept : id(buffer.id), nr_of_elements(buffer.nr_of_elements) {}

Buffer&& forward(Buffer& buffer) noexcept {
	return static_cast<Buffer&&>(buffer);
}

Buffer& Buffer::operator=(const Buffer& b) {
	this->id = b.id;
	this->nr_of_elements = b.nr_of_elements;
	return *this;
}

void Buffer::update(GLfloat* data, GLsizei count, GLuint nr_of_elements) {
	this->nr_of_elements = nr_of_elements;
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

GLuint Buffer::get_id() const noexcept {
	return id;
}
GLuint Buffer::get_nr_of_elements() const noexcept {
	return nr_of_elements;
}