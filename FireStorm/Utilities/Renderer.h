#pragma once

#include "../Buffers/Buffer.h"
#include "../Buffers/IndexBuffer.h"
#include "../Buffers/VertexArray.h"
#include "../Utilities/Texture.hpp"
#include "../Shaders/Shader.hpp"

//GLuint background_indices[] = { 0, 1, 2,  0, 2, 3 };

class Renderer
{
private:
	GLFWwindow* window;
public:
	Renderer(GLFWwindow* _window);
	void backgound();
};