#include "Laser.hpp"

GLuint texture_indices_temp[] = { 0, 1, 2,  0, 2, 3 }; //extern

float color_blue[] {
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f
};

Laser::Laser(float* starship_position, float width, float height) {
	float medie_x, medie_y;

	medie_x = (starship_position[2] + starship_position[4]) / 2;
	medie_y = (starship_position[3] + starship_position[5]) / 2;

	float laser_pos[] = {
		medie_x - width, medie_y,
		medie_x + width, medie_y,
		medie_x + width, medie_y + height,
		medie_x - width, medie_y + height
	};

	Buffer* laser_coord_vbo1 = new Buffer(laser_pos, 2 * 4, 2);
	Buffer* laser_coord_vbo2 = new Buffer(color_blue, 4 * 4, 4);

	laser_sprite.addBuffer(laser_coord_vbo1, 0);
	laser_sprite.addBuffer(laser_coord_vbo2, 1);

	laser_ibo.create_IndexBuffer(texture_indices_temp, 6);

	laser_sprite.bind();
	laser_ibo.bind();

	laser_shader.createShader("Shaders/laser_vert.shader", "Shaders/laser_frag.shader");
	laser_shader.bind();
}

VertexArray Laser::getSprite() {
	return this->laser_sprite;
}

IndexBuffer Laser::get_ibo() {
	return this->laser_ibo;
}

void Laser::bind() const noexcept {
	laser_sprite.bind();
	laser_ibo.bind();
	laser_shader.bind();
	//drawCall_quad(laser_sprite, laser_ibo);
}

void Laser::unbind() const noexcept {
	laser_sprite.unbind();
	laser_ibo.unbind();
}

Laser::~Laser() {
	delete[] laser_coord_vbo1;
	delete[] laser_coord_vbo2;
}