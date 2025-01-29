#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Buffer.hpp"
#include "IndexBuffer.hpp"
#include "VertexArray.hpp"
#include "../Textures/Texture.hpp" // del
#include "../Shaders/Shader.hpp"

#include <vector>
#include <string>

class Mesh {

private:
	std::vector<GLuint> indices; // order of rendering vertexes

	std::vector<Buffer*> buffers;
	VertexArray sprite;
	IndexBuffer ibo;

	Shader shader;

	Texture texture; // exclude

public:
	Mesh();
	Mesh(GLuint indices[], const std::string& vert_shader, const std::string& frag_shader);

	void addIndices(std::vector<GLuint>& indices);
	void addIndices(GLuint indices[], int size);
	void addFloatBuffer(GLfloat bufferData[]);
	void addUIntBuffer(GLuint bufferData[]);
	void addShader(const std::string& vert_shader, const std::string& frag_shader);
};


//// Walls
//GLuint left_wall_indices[] = { 0, 1, 2,  0, 2, 3 };
//
//VertexArray left_wall_sprite;
//Buffer* left_wall_vbo1 = new Buffer(left_wall_vertices, 4 * 3, 3);
//Buffer* left_wall_vbo2 = new Buffer(texture_poz, 4 * 2, 2);
//IndexBuffer left_wall_ibo(left_wall_indices, 6);
//
//left_wall_sprite.addBuffer(left_wall_vbo1, 0);
//left_wall_sprite.addBuffer(left_wall_vbo2, 2); // texture coords
//
//left_wall_sprite.bind();
//left_wall_ibo.bind();
//
//Shader left_wall_shader;
//left_wall_shader.createShader("Shaders/terrain_texture_vert.shader", "Shaders/left_wall_texture_frag.shader");
//left_wall_shader.bind();
//
//Texture left_wall_texture("Textures/brick_wall.png");
//left_wall_texture.bind();
//left_wall_shader.bind();
//left_wall_shader.uniform1i("left_wall_texture", 0);