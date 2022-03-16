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

    this->position[0] = 0.50f;
    this->position[1] = 0.50f;
    this->position[2] = 0.50f;
    this->position[3] = 0.85f;
    this->position[4] = 0.75f;
    this->position[5] = 0.85f;
    this->position[6] = 0.75f;
    this->position[7] = 0.50f;

	float texture_poz[] = {
        0.00f, 0.00f,
        0.00f, 1.00f,
        1.00f, 1.00f,
        1.00f, 0.00f
    };

    GLuint texture_indices_temp[] = { 0, 1, 2,  0, 2, 3 };

	enemy_coord_vbo1.update(this->position, 8 * 2, 2);
	enemy_coord_vbo2.update(texture_poz, 8 * 2, 2);

    Buffer* e_vbo1 = new Buffer(this->position, 8 * 2, 2);
    Buffer* e_vbo2 = new Buffer(texture_poz, 8 * 2, 2);

	enemy_sprite.addBuffer(e_vbo1, 0);
	//enemy_sprite.addBuffer(&enemy_coord_vbo1, 0);
	enemy_sprite.addBuffer(e_vbo2, 2);
	//enemy_sprite.addBuffer(&enemy_coord_vbo2, 2);

    enemy_ibo.createIndexBuffer(texture_indices_temp, 6);

	enemy_sprite.bind();
	enemy_ibo.bind();

	enemy_shader.createShader("Shaders/enemy_texture_vert.shader", "Shaders/enemy_texture_frag.shader");
	//enemy_shader.createShader("Shaders/vert_texture.shader", "Shaders/frag_texture.shader");
    enemy_shader.bind();

    enemy_texture.getTexture("Textures/enemy_attacker.png");
    enemy_texture.bind();

    enemy_shader.uniform1i("enemy_texture", 0);
}

Enemy::Enemy(float position[8]) {

    this->position[0] = position[0];
    this->position[1] = position[1];
    this->position[2] = position[2];
    this->position[3] = position[3];
    this->position[4] = position[4];
    this->position[5] = position[5];
    this->position[6] = position[6];
    this->position[7] = position[7];

    float texture_poz[] = {
        0.00f, 0.00f,
        0.00f, 1.00f,
        1.00f, 1.00f,
        1.00f, 0.00f
    };

    GLuint texture_indices_temp[] = { 0, 1, 2,  0, 2, 3 };

    enemy_coord_vbo1.update(this->position, 8 * 2, 2);
    enemy_coord_vbo2.update(texture_poz, 8 * 2, 2);

    Buffer* e_vbo1 = new Buffer(this->position, 8 * 2, 2);
    Buffer* e_vbo2 = new Buffer(texture_poz, 8 * 2, 2);

    enemy_sprite.addBuffer(e_vbo1, 0);
    enemy_sprite.addBuffer(e_vbo2, 2);

    enemy_ibo.createIndexBuffer(texture_indices_temp, 6);

    enemy_sprite.bind();
    enemy_ibo.bind();

    enemy_shader.createShader("Shaders/enemy_texture_vert.shader", "Shaders/enemy_texture_frag.shader");
    enemy_shader.bind();

    enemy_texture.getTexture("Textures/enemy_attacker.png");
    enemy_texture.bind();

    enemy_shader.uniform1i("enemy_texture", 0);
}

Enemy& Enemy::operator=(const Enemy& e) {
    this->enemy_sprite = e.enemy_sprite;
    this->enemy_coord_vbo1 = e.enemy_coord_vbo1;
    this->enemy_coord_vbo2 = e.enemy_coord_vbo2;
    this->enemy_ibo = e.enemy_ibo;
    this->enemy_shader = e.enemy_shader;
    this->enemy_texture = e.enemy_texture;
    for(int i(0); i < 8; ++i)
        this->position[i] = e.position[i];

    return *this;
}

void Enemy::bind() const noexcept {
    enemy_sprite.bind();
    enemy_ibo.bind();
    enemy_texture.bind();
    enemy_shader.bind();
    //enemy_texture.bind();
}

Enemy::~Enemy() {
}