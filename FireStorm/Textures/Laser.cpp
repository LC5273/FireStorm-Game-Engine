#include "Laser.hpp"

GLuint texture_indices_temp[] = { 0, 1, 2,  0, 2, 3 }; //extern

float color_blue[]{
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f
};

Laser::Laser(float* starship_position, float width, float height) {
/*
medie_x = (3.x + 4.x) / 2;
medie_y = (3.y + 4.y) / 2;

1': medie_x - latime, medie_y
2': medie_x + latime, medie_y
3': medie_x - latime, medie_y + lungime
4': medie_x + latime, medie_y + lungime
*/
	float medie_x, medie_y;

	medie_x = (starship_position[4] + starship_position[6]) / 2;
	medie_y = (starship_position[7] + starship_position[7]) / 2;

	float laser_pos[] = {
		medie_x - width, medie_y,
		medie_x - width, medie_y,
		medie_x - width, medie_y + height,
		medie_x - width, medie_y + height
	};

	laser_ibo = new IndexBuffer(texture_indices_temp, 6);

}

Laser::Laser(float* starship_position, float width, float height, bool triangle) {
	/*
	medie_x = (3.x + 4.x) / 2;
	medie_y = (3.y + 4.y) / 2;

	1': medie_x - latime, medie_y
	2': medie_x + latime, medie_y
	3': medie_x - latime, medie_y + lungime
	4': medie_x + latime, medie_y + lungime
	*/
	float medie_x, medie_y;

	medie_x = (starship_position[4] + starship_position[6]) / 2;
	medie_y = (starship_position[5] + starship_position[7]) / 2;

	float laser_pos1[] = {
		medie_x - width, medie_y,
		medie_x - width, medie_y,
		medie_x - width, medie_y + height
	};
	float laser_pos2[] = {
		medie_x - width, medie_y,
		medie_x - width, medie_y + height,
		medie_x - width, medie_y + height
	};

	laser_coord_vbo1 = new Buffer(laser_pos1, 4 * 2, 2);
	laser_coord_vbo2 = new Buffer(color_blue, 4 * 2, 2);
	laser_coord_vbo3 = new Buffer(laser_pos2, 4 * 2, 2);
	laser_coord_vbo4 = new Buffer(color_blue, 4 * 2, 2);

	laser_ibo = new IndexBuffer(texture_indices_temp, 6);

	laser_sprite1.addBuffer(laser_coord_vbo1, 0);
	laser_sprite1.addBuffer(laser_coord_vbo2, 1);
	laser_sprite2.addBuffer(laser_coord_vbo3, 0);
	laser_sprite2.addBuffer(laser_coord_vbo4, 1);
}

VertexArray Laser::getSprite1()
{
	return this->laser_sprite1;
}

VertexArray Laser::getSprite2()
{
	return this->laser_sprite2;
}

IndexBuffer Laser::get_ibo() {
	return *(this->laser_ibo);
}

void Laser::bind() const noexcept {
	laser_sprite1.bind();
	//laser_sprite2.bind();
	laser_ibo->bind();
}

void Laser::unbind() const noexcept {
	laser_sprite1.unbind();
	//laser_sprite2.unbind();
	laser_ibo->unbind();
}

Laser::~Laser() {
	delete[] laser_coord_vbo1;
	delete[] laser_coord_vbo2;
	delete[] laser_coord_vbo3;
	delete[] laser_coord_vbo4;
	delete[] laser_ibo;
}