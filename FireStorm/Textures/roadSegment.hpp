#pragma once

#include "../Buffers/Buffer.hpp"
#include "../Buffers/IndexBuffer.hpp"
#include "../Buffers/VertexArray.hpp"
#include "../Shaders/Shader.hpp"
#include "Texture.hpp"

class roadSegment
{
private:
	VertexArray road_sprite;
	Buffer* road_coord_vbo1;
	Buffer* road_coord_vbo2;
	IndexBuffer road_ibo;
	//Shader road_shader;
public:
	Shader road_shader;

	roadSegment(float coord[24]);
	//roadSegment(float x, float y, float z); ?

	inline VertexArray getSprite() const noexcept { return road_sprite; }
	inline IndexBuffer getIbo() const noexcept { return road_ibo; }
	inline Shader getShader() noexcept { return road_shader; }

	void bind() const noexcept;
	void unbind() const noexcept;

	~roadSegment();
};

