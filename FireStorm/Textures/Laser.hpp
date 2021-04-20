#pragma once

#include "../Buffers/Buffer.hpp"
#include "../Buffers/IndexBuffer.hpp"
#include "../Buffers/VertexArray.hpp"
#include "../Shaders/Shader.hpp"

class Laser
{
public:
	VertexArray laser_sprite;
	Buffer* laser_coord_vbo1;
	Buffer* laser_coord_vbo2;
	//Buffer laser_temp;
	IndexBuffer laser_ibo;
	Shader laser_shader;
	float laser_position[8];

public:
	Laser(float* starship_position, float width, float height);
	//Laser(const Laser& laser);
	//Laser(Laser&& laser);

	VertexArray getSprite();
	IndexBuffer get_ibo();

	void bind() const noexcept;
	void unbind() const noexcept;

	void travel();
	bool valid();
	bool collision(float object_coord[8]);

	//~Laser();
};

