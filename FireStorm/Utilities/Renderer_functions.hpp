#pragma once

#include "../Buffers/Buffer.hpp"
#include "../Buffers/IndexBuffer.hpp"
#include "../Buffers/VertexArray.hpp"
#include "../Textures/Texture.hpp"
#include "../Shaders/Shader.hpp"

void key_callback_test(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		std::cout << "E\n";
}


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
void drawCall_cube(const VertexArray& sprite, const IndexBuffer& ibo) {
	sprite.bind();
	ibo.bind();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
	ibo.unbind();
	sprite.unbind();
};