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

	for (int i(0); i < 8; ++i)
		laser_position[i] = laser_pos[i];

	laser_coord_vbo1 = new Buffer(laser_pos, 2 * 4, 2);
	Buffer* laser_coord_vbo2 = new Buffer(color_blue, 4 * 4, 4);

	laser_sprite.addBuffer(laser_coord_vbo1, 0);
	laser_sprite.addBuffer(laser_coord_vbo2, 1);

	laser_ibo.createIndexBuffer(texture_indices_temp, 6);

	laser_sprite.bind();
	laser_ibo.bind();

	laser_shader.createShader("Shaders/laser_vert.shader", "Shaders/laser_frag.shader");
	laser_shader.bind();
}
/*
Laser::Laser(const Laser& laser) {
	this->laser_sprite = laser.laser_sprite;
	this->laser_ibo = laser.laser_ibo;
	this->laser_shader = laser.laser_shader;

	//this->laser_coord_vbo1 = new Buffer(laser.laser_coord_vbo1->get_id(), laser.laser_coord_vbo1->get_nr_of_elements());
	this->laser_coord_vbo1 = new Buffer(laser.laser_coord_vbo1->get_id(), 8);
	//this->laser_coord_vbo2 = new Buffer(laser.laser_coord_vbo2->get_id(), laser.laser_coord_vbo2->get_nr_of_elements());

	for (int i(0); i < 8; ++i)
		this->laser_position[i] = laser.laser_position[i];
}
/*
Laser::Laser(const Laser& laser) {
	this->laser_sprite = laser.laser_sprite;
	this->laser_ibo = laser.laser_ibo;
	this->laser_shader = laser.laser_shader;

	float* laser_pos = new float[8];
	for (int i(0); i < 8; ++i)
		laser_pos[i] = laser.laser_position[i];

	this->laser_coord_vbo2 = new Buffer(laser_pos, 2 * 4, 2);
	this->laser_coord_vbo2 = new Buffer(color_blue, 4 * 4, 2);
	
	for (int i(0); i < 8; ++i)
		this->laser_position[i] = laser.laser_position[i];

	delete[] laser_pos;
}
*/

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

void Laser::travel() {
	laser_position[1] += 0.001f;
	laser_position[3] += 0.001f;
	laser_position[5] += 0.001f;
	laser_position[7] += 0.001f;

	laser_coord_vbo1->update(laser_position, 2 * 4, 2);
}

bool Laser::valid() {
	if (laser_position[1] >= 1.0f)
		return false;
	return true;
}

bool Laser::collision(float object_coord[8]) {

	if ((laser_position[4] >= object_coord[0] &&
		laser_position[4] <= object_coord[3] &&
		laser_position[5] >= object_coord[1]) ||
		(laser_position[6] <= object_coord[2] &&
			laser_position[6] >= object_coord[1] &&
			laser_position[7] >= object_coord[1]))
		return true;

	if ((laser_position[4] >= object_coord[0] &&
		laser_position[4] <= object_coord[2] &&
		laser_position[5] >= object_coord[1]) ||
		(laser_position[6] <= object_coord[2] &&
			laser_position[6] >= object_coord[0] &&
			laser_position[7] >= object_coord[1]))
		return true;

	return false;
}

/*
Laser::~Laser() {
	delete[] laser_coord_vbo1;
	delete[] laser_coord_vbo2;
}
*/