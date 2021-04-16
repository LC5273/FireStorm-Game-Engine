#include "Enemy.hpp"

//GLuint texture_indices_temp[] = { 0, 1, 2,  0, 2, 3 }; //extern
/*
float texture_pos[] = {
    0.00f, 0.00f,
    0.00f, 0.25f,
    0.25f, 0.25f,
    0.25f, 0.00f
};
float texture_poz[] = {
    0.00f, 0.00f,
    0.00f, 1.00f,
    1.00f, 1.00f,
    1.00f, 0.00f
};

/*
    0.75f, 0.75f,
    0.75f, 1.00f,
    1.00f, 1.00f,
    1.00f, 0.75f
*/

Enemy::Enemy() {

    this->position[0] = 0.75f;
    this->position[1] = 0.75f;
    this->position[2] = 0.75f;
    this->position[3] = 1.00f;
    this->position[4] = 1.00f;
    this->position[5] = 1.00f;
    this->position[6] = 1.00f;
    this->position[7] = 0.75f;

	float texture_poz[] = {
        0.00f, 0.00f,
        0.00f, 1.00f,
        1.00f, 1.00f,
        1.00f, 0.00f
    };

    GLuint texture_indices_temp[] = { 0, 1, 2,  0, 2, 3 };

	enemy_coord_vbo1.update(this->position, 8 * 2, 2);
	enemy_coord_vbo2.update(texture_poz, 8 * 2, 2);

	enemy_sprite.addBuffer(&enemy_coord_vbo1, 0);
	enemy_sprite.addBuffer(&enemy_coord_vbo2, 2);

    enemy_ibo.createIndexBuffer(texture_indices_temp, 6);

	enemy_sprite.bind();
	enemy_ibo.bind();

	enemy_shader.createShader("../Shaders/enemy_texture_vert.shader", "../Shaders/enemy_texture_frag.shader");
    enemy_shader.bind();

    enemy_texture.getTexture("../Textures/enemy_lurker.png");
    enemy_texture.bind();

    enemy_shader.uniform1i("texture1", 0);
}

void Enemy::bind() const noexcept {
    enemy_sprite.bind();
    enemy_ibo.bind();
    enemy_texture.bind();
    enemy_shader.bind();
}

Enemy::~Enemy() {
}