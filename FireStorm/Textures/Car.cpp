#include "Car.hpp"

float color_purple[]{
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f
};

GLuint car_indices_right[] =
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

Car::Car(float coord[24]) {
    for (int i(0); i < 24; ++i)
        this->coord[i] = coord[i];

    car_coord_vbo1 = new Buffer(coord, 8 * 3, 3);
    car_coord_vbo2 = new Buffer(color_purple, 8 * 4, 4);

    car_ibo.createIndexBuffer(car_indices_right, 36);

    car_sprite.addBuffer(car_coord_vbo1, 0);
    car_sprite.addBuffer(car_coord_vbo2, 1);

    car_shader.createShader("Shaders/road_vert.shader", "Shaders/road_frag.shader");
    car_shader.bind();

}

void Car::updateCoordVbo() {
    car_coord_vbo1->update(this->coord, 8 * 3, 3);
}

void Car::bind() const noexcept {
    car_sprite.bind();
    car_ibo.bind();
    car_shader.bind();
}

void Car::unbind() const noexcept {
    car_ibo.unbind();
    car_sprite.unbind();
}

Car::~Car() {
    delete[] car_coord_vbo1;
    delete[] car_coord_vbo2;
}