#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
private:
	GLFWwindow* window;
	int width, height;
public:
	Window();
	Window(int width, int height, const char* title);
	bool closed();
	void resize();
	~Window();
};

