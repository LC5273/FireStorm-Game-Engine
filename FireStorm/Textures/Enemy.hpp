#pragma once

#include "../Buffers/Buffer.hpp"
#include "../Buffers/IndexBuffer.hpp"
#include "../Buffers/VertexArray.hpp"
#include "../Shaders/Shader.hpp"
#include "Texture.hpp"

class Enemy
{
public:
	VertexArray enemy_sprite;
	Buffer enemy_coord_vbo1;
	Buffer enemy_coord_vbo2;
	IndexBuffer enemy_ibo;
	Shader enemy_shader;
	Texture enemy_texture;
	float position[8];

public:
	Enemy();
	Enemy(float position[8]);
	
	//inline IndexBuffer getIbo() const noexcept { return enemy_ibo; }
	//inline VertexArray getVao() const noexcept { return enemy_sprite; }

	float* getPosition() const noexcept;

	void bind() const noexcept;

	~Enemy();
};

