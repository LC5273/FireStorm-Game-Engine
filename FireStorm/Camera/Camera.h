#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

//#include <glad/glad.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <../../../Dependencies/glm/glm.hpp>
#include <../../../Dependencies/glm/gtc/matrix_transform.hpp>
#include <../../../Dependencies/glm/gtc/type_ptr.hpp>
#include <../../../Dependencies/glm/gtx/rotate_vector.hpp>
#include <../../../Dependencies/glm/gtx/vector_angle.hpp>

//#include "shaderClass.h"
#include "../Shaders/Shader.hpp"

class Camera
{
public:
	// Stores the main vectors of the camera
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	// Prevents the camera from jumping around when first clicking left click
	bool firstClick = true;

	// Stores the width and height of the window
	int width;
	int height;

	// Adjust the speed of the camera and it's sensitivity when looking around
	float speed = 0.000001f;
	float sensitivity = 10.0f;

	// Camera constructor to set up initial values
	Camera(int width, int height, glm::vec3 position);

	// Updates the camera matrix to the Vertex Shader
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
	// Exports the camera matrix to a shader
	void Matrix(Shader& shader, const char* uniform);
	// Handles camera inputs
	void Inputs(GLFWwindow* window);
};
#endif