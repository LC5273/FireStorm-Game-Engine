#pragma once

#include "../Buffers/Buffer.hpp"
#include "../Buffers/IndexBuffer.hpp"
#include "../Buffers/VertexArray.hpp"
#include "../Shaders/Shader.hpp"
#include "Texture.hpp"

class Enemy
{
private:
	VertexArray enemy_sprite;
	Buffer enemy_coord_vbo1;
	Buffer enemy_coord_vbo2;
	IndexBuffer enemy_ibo;
	Shader enemy_shader;
	float position[8];

public:
	Enemy();
	//Enemy();

	~Enemy();
};

