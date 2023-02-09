#include "Particle.hpp"

float color_purple[] {
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f,
    0.8f, 0.0f, 0.8f, 1.0f
};

Particle::Particle() {}

Particle::Particle(float coord[720]) {
    for (int i(0); i < 720; ++i)
        this->coord[i] = coord[i];

    srand(time(NULL));
    angle = (rand() % 10);
    angle /= 1000000;
    angle = 0;
    speed = (rand() % 1000);
    speed /= 100000;

    float x, y, z, k;
    x = (rand() % 100);
    x /= 100;
    y = (rand() % 100);
    y /= 100;
    z = (rand() % 100); 
    z /= 100;

    k = (rand() % 100);
    if (k < 50)
        x = 0.0f - x;

    k = (rand() % 100);
    if (k < 50)
        y = 0.0f - y;

    k = (rand() % 100);
    if (k < 50)
        z = 0.0f - z;


    direction = glm::vec3(x, y, z);
    centerOfObject = glm::vec3((ParticleCoord[104 * 3] + ParticleCoord[114 * 3]) / 2, (ParticleCoord[104 * 3 + 1] + ParticleCoord[114 * 3 + 1]) / 2, (ParticleCoord[104 * 3 + 2] + ParticleCoord[114 * 3 + 2]) / 2);


    Particle_coord_vbo1 = new Buffer(coord, 240 * 3, 3);
    Particle_coord_vbo2 = new Buffer(color_purple, 240 * 4, 4);

    Particle_ibo.createIndexBuffer(ParticleIbo, 1320);

    Particle_sprite.addBuffer(Particle_coord_vbo1, 0);
    Particle_sprite.addBuffer(Particle_coord_vbo2, 1);

    Particle_shader.createShader("Shaders/road_vert.shader", "Shaders/road_frag.shader");
    Particle_shader.bind();
}

Particle::Particle(const Particle& particle) {
    for (int i(0); i < 720; ++i)
        this->coord[i] = particle.coord[i];

    this->angle = particle.angle;
    this->speed = particle.speed;
    this->direction = particle.direction;

    this->Particle_coord_vbo1 = new Buffer(this->coord, 240 * 3, 3);
    this->Particle_coord_vbo2 = new Buffer(color_purple, 240 * 4, 4); //3

    this->Particle_ibo.createIndexBuffer(ParticleIbo, 1320);

    this->Particle_sprite.addBuffer(this->Particle_coord_vbo1, 0);
    this->Particle_sprite.addBuffer(this->Particle_coord_vbo2, 1);

    this->Particle_shader.createShader("Shaders/road_vert.shader", "Shaders/road_frag.shader");
    this->Particle_shader.bind();
}

void Particle::updateCoordVbo() {
    Particle_coord_vbo1->update(this->coord, 8 * 3, 3);
}

Particle& Particle::operator=(const Particle& particle) {
    for (int i(0); i < 720; ++i)
        this->coord[i] = particle.coord[i];

    this->angle = particle.angle;
    this->speed = particle.speed;
    this->direction = particle.direction;
    this->centerOfObject = particle.centerOfObject;

    this->Particle_coord_vbo1 = new Buffer(this->coord, 240 * 3, 3);
    this->Particle_coord_vbo2 = new Buffer(color_purple, 240 * 4, 3); //3

    this->Particle_ibo.createIndexBuffer(ParticleIbo, 1320);

    this->Particle_sprite.addBuffer(this->Particle_coord_vbo1, 0);
    this->Particle_sprite.addBuffer(this->Particle_coord_vbo2, 1);

    this->Particle_shader.createShader("Shaders/road_vert.shader", "Shaders/road_frag.shader");
    this->Particle_shader.bind();

    return *this;
}

void Particle::updateMatrix(glm::mat4 matrix) {
    GLuint modelMatrixLoc = glGetUniformLocation(Particle_shader.getID(), "model");
    glUniformMatrix4fv(modelMatrixLoc, 1, false, glm::value_ptr(matrix));
}

void Particle::updateProjMatrix(glm::mat4 matrix) {
    GLuint modelMatrixLoc = glGetUniformLocation(Particle_shader.getID(), "projection");
    glUniformMatrix4fv(modelMatrixLoc, 1, false, glm::value_ptr(matrix));
}

void Particle::bind() const noexcept {
    Particle_sprite.bind();
    Particle_ibo.bind();
    Particle_shader.bind();
}

void Particle::unbind() const noexcept {
    Particle_ibo.unbind();
    Particle_sprite.unbind();
}

Particle::~Particle() {
    delete[] Particle_coord_vbo1;
    delete[] Particle_coord_vbo2;
}