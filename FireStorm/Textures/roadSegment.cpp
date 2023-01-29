#include "roadSegment.hpp"

float color_grey[]{
    0.0f, 0.1f, 0.2f, 1.0f,
    0.0f, 0.1f, 0.2f, 1.0f,
    0.0f, 0.1f, 0.2f, 1.0f,
    0.0f, 0.1f, 0.2f, 1.0f,
    0.0f, 0.1f, 0.2f, 1.0f,
    0.0f, 0.1f, 0.2f, 1.0f,
    0.0f, 0.1f, 0.2f, 1.0f,
    0.0f, 0.1f, 0.2f, 1.0f
};

GLuint cube_indices_right[] =
{
    0, 1, 2,
    1, 2, 3,
    2, 3, 4,
    3, 4, 5,
    4, 5, 6,
    5, 6, 7,
    6, 7, 0,
    7, 0, 1,
    1, 3, 7,
    3, 7, 5,
    0, 2, 6,
    2, 6, 4
};

roadSegment::roadSegment(float coord[24]) {

	road_coord_vbo1 = new Buffer(coord, 8 * 3, 3);
	road_coord_vbo2 = new Buffer(color_grey, 8 * 4, 4);

    road_ibo.createIndexBuffer(cube_indices_right, 36);

    road_sprite.addBuffer(road_coord_vbo1, 0);
    road_sprite.addBuffer(road_coord_vbo2, 1);

    road_shader.createShader("Shaders/road_vert.shader", "Shaders/road_frag.shader");
    road_shader.bind();

}

void roadSegment::bind() const noexcept {
	road_sprite.bind();
	road_ibo.bind();
	road_shader.bind();
}

void roadSegment::unbind() const noexcept {
	road_ibo.unbind();
	road_sprite.unbind();
}

roadSegment::~roadSegment() {
	delete[] road_coord_vbo1;
	delete[] road_coord_vbo2;
}