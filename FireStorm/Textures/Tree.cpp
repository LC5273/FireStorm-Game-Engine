#include "Tree.hpp"

float color_brown[]{
    0.6f, 0.3f, 0.0f, 1.0f,
    0.6f, 0.3f, 0.0f, 1.0f,
    0.6f, 0.3f, 0.0f, 1.0f,
    0.6f, 0.3f, 0.0f, 1.0f,
    0.6f, 0.3f, 0.0f, 1.0f,
    0.6f, 0.3f, 0.0f, 1.0f,
    0.6f, 0.3f, 0.0f, 1.0f,
    0.6f, 0.3f, 0.0f, 1.0f,
};

float color_green[]{
    0.0f, 1.0f, 0.1f, 1.0f,
    0.0f, 1.0f, 0.1f, 1.0f,
    0.0f, 1.0f, 0.1f, 1.0f,
    0.0f, 1.0f, 0.1f, 1.0f,
    0.0f, 1.0f, 0.1f, 1.0f,
    0.0f, 1.0f, 0.1f, 1.0f,
    0.0f, 1.0f, 0.1f, 1.0f,
    0.0f, 1.0f, 0.1f, 1.0f
};

GLuint tree_indices_right[] =
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

Tree::Tree() {}

//Tree::Tree(float coord[12]) {
Tree::Tree(float coordLog[24], float coordLeaves[24]) {
    for (int i(0); i < 24; ++i) {
        this->coord_log[i] = coordLog[i];
        this->coord_leaves[i] = coordLeaves[i];
    }

    tree_log_coord_vbo1 = new Buffer(coord_log, 8 * 3, 3);
    tree_log_coord_vbo2 = new Buffer(color_brown, 8 * 4, 4);
    tree_leaves_coord_vbo1 = new Buffer(coord_leaves, 8 * 3, 3);
    tree_leaves_coord_vbo2 = new Buffer(color_green, 8 * 4, 4);

    tree_log_ibo.createIndexBuffer(tree_indices_right, 36);
    tree_leaves_ibo.createIndexBuffer(tree_indices_right, 36);

    tree_log_sprite.addBuffer(tree_log_coord_vbo1, 0);
    tree_log_sprite.addBuffer(tree_log_coord_vbo2, 1);
    tree_leaves_sprite.addBuffer(tree_leaves_coord_vbo1, 0);
    tree_leaves_sprite.addBuffer(tree_leaves_coord_vbo2, 1);

    tree_log_shader.createShader("Shaders/road_vert.shader", "Shaders/road_frag.shader");
    tree_log_shader.bind();

    tree_leaves_shader.createShader("Shaders/road_vert.shader", "Shaders/road_frag.shader");
    tree_leaves_shader.bind();

}

void Tree::updateCoordVbo() {
    tree_log_coord_vbo1->update(this->coord_log, 8 * 3, 3);
    tree_leaves_coord_vbo1->update(this->coord_leaves, 8 * 3, 3);
}

void Tree::updateLogMatrix(glm::mat4 matrix) {
    GLuint modelMatrixLoc = glGetUniformLocation(tree_log_shader.getID(), "model");
    glUniformMatrix4fv(modelMatrixLoc, 1, false, glm::value_ptr(matrix));
}
void Tree::updateLeavesMatrix(glm::mat4 matrix) {
    GLuint modelMatrixLoc = glGetUniformLocation(tree_leaves_shader.getID(), "model");
    glUniformMatrix4fv(modelMatrixLoc, 1, false, glm::value_ptr(matrix));
}

void Tree::bindLog() const noexcept {
    tree_log_sprite.bind();
    tree_log_ibo.bind();
    tree_log_shader.bind();
}

void Tree::unbindLog() const noexcept {
    tree_log_ibo.unbind();
    tree_log_sprite.unbind();
}

void Tree::bindLeaves() const noexcept {
    tree_leaves_sprite.bind();
    tree_leaves_ibo.bind();
    tree_leaves_shader.bind();
}

void Tree::unbindLeaves() const noexcept {
    tree_leaves_ibo.unbind();
    tree_leaves_sprite.unbind();
}

Tree::~Tree() {
    delete[] tree_log_coord_vbo1;
    delete[] tree_log_coord_vbo2;
    delete[] tree_leaves_coord_vbo1;
    delete[] tree_leaves_coord_vbo2;
}