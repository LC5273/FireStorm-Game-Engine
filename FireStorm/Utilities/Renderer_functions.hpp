#pragma once

#include "../Buffers/Buffer.h"
#include "../Buffers/IndexBuffer.h"
#include "../Buffers/VertexArray.h"
#include "../Utilities/Texture.hpp"
#include "../Shaders/Shader.hpp"

void drawCall_triangle(const VertexArray& sprite, const IndexBuffer& ibo) {
	sprite.bind();
	ibo.bind();
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	ibo.unbind();
	sprite.unbind();
};
void drawCall_quad(const VertexArray& sprite, const IndexBuffer& ibo) {
	sprite.bind();
	ibo.bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	ibo.unbind();
	sprite.unbind();
};