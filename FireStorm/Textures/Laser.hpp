#pragma once

#include "../Buffers/Buffer.hpp"
#include "../Buffers/IndexBuffer.hpp"
#include "../Buffers/VertexArray.hpp"
#include "../Shaders/Shader.hpp"
//#include "../Utilities/Renderer_functions.hpp"

class Laser
{
public:
	VertexArray laser_sprite;
	VertexArray laser_sprite1;
	VertexArray laser_sprite2;
	Buffer* laser_coord_vbo1;
	Buffer* laser_coord_vbo2;
	IndexBuffer laser_ibo;
	Shader laser_shader;

public:
	Laser(float* starship_position, float width, float height);

	VertexArray getSprite();
	IndexBuffer get_ibo();

	void bind() const noexcept;
	void unbind() const noexcept;

	void travel();

	~Laser();
};

