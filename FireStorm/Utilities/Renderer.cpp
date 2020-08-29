#include "Renderer.h"

float background_pos[] = {
    -1.00f, -1.00f,
    -1.00f,  1.00f,
     1.00f,  1.00f,
     1.00f, -1.00f
};
float background_coord[] = {
    0.00f, 0.00f,
    0.00f, 1.00f,
    1.00f, 1.00f,
    1.00f, 0.00f
};

GLuint background_indices[] = { 0, 1, 2,  0, 2, 3 };

Renderer::Renderer(GLFWwindow* _window) {
    window = _window;
}

void Renderer::backgound() {
    VertexArray sprite;
    Buffer* vbo1 = new Buffer(background_pos, 8 * 2, 2);
    Buffer* vbo2 = new Buffer(background_coord, 8 * 2, 2);
    IndexBuffer ibo(background_indices, 6);
    
    sprite.addBuffer(vbo1, 0);
    sprite.addBuffer(vbo2, 2);

    sprite.bind();
    ibo.bind();


    Shader s;
    s.createShader("Shaders/vert_background.shader", "Shaders/frag_background.shader");
    s.bind();

    Texture texture1("Textures/background.png");
    texture1.bind(1);

    s.uniform1i(window, "texture1", 0);
}