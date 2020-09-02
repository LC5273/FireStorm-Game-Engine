#include "Window.hpp"

Window::Window() {
	window = NULL;
	width = 0;
	height = 0;
}
Window::Window(int width, int height, const char* title) {
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	
	this->width = width;
	this->height = height;
}

bool Window::closed() {
	return glfwWindowShouldClose(window);
}

void Window::resize() {
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
}

Window::~Window() {
	if (window)
		delete[] window;
}