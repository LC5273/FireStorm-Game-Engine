#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Shader
{
private:
	unsigned int id;
public:
	//Shader(const std::string& vertexShader, const std::string& fragmentShader);
	Shader();

	void createShader(const std::string& vertexShader, const std::string& fragmentShader);

	friend std::stringstream file2string(const std::string& filepath);
	friend unsigned int CompileShader(unsigned int type, std::string source);
	friend void getCursorPos(GLFWwindow* window, double x, double y);

	inline unsigned int getID() { return id; }


	void uniform2f_mouse_pos(GLFWwindow* window, const char* field);
	void uniform1i(GLFWwindow* window, const char* field, int value);

	void bind() const;
	void unbind() const;
};
