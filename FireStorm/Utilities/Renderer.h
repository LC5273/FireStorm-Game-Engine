#pragma once

#include "../Buffers/Buffer.h"
#include "../Buffers/IndexBuffer.h"
#include "../Buffers/VertexArray.h"
#include "../Utilities/Texture.h"
#include "../Shaders/Shader.h"

//GLuint background_indices[] = { 0, 1, 2,  0, 2, 3 };

class Renderer
{
private:
	GLFWwindow* window;
public:
	Renderer(GLFWwindow* _window);
	void backgound();
};

