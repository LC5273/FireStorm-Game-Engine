#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Buffers/Buffer.hpp"
#include "../Buffers/IndexBuffer.hpp"
#include "../Buffers/VertexArray.hpp"
#include "../Textures/Texture.hpp"
#include "../Shaders/Shader.hpp"

#include "../Utilities/Renderer_functions.hpp"

bool exit_main_s = false;

void key_callback_main_menu(GLFWwindow* window, int key, int scancode, int action, int mods) {
    //if (key == GLFW_MOUSE_BUTTON_1 && action == GLFW_RELEASE)
    if (key == GLFW_KEY_A && action == GLFW_RELEASE)
        exit_main_s = true;
}

void main_screen(GLFWwindow* window) {
    if (!window)
    {
        std::cout << "Window not valid";
        glfwTerminate();
    }

    // Initialization

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

    VertexArray background_sprite;
    Buffer* background_vbo1 = new Buffer(background_pos, 8 * 2, 2);
    Buffer* background_vbo2 = new Buffer(background_coord, 8 * 2, 2);
    IndexBuffer background_ibo(background_indices, 6);

    background_sprite.addBuffer(background_vbo1, 0);
    background_sprite.addBuffer(background_vbo2, 2);

    background_sprite.bind();
    background_ibo.bind();


    Shader background_shader;
    background_shader.createShader("Shaders/vert_background.shader", "Shaders/frag_background.shader");
    background_shader.bind();

    Texture background_texture("Textures/background.png");
    //Texture background_texture("Textures/main_screen.png");
    background_texture.bind();

    background_shader.uniform1i("texture1", 0);

    while (!glfwWindowShouldClose(window) && !exit_main_s)
    {
        background_texture.bind();
        background_shader.bind();
        drawCall_quad(background_sprite, background_ibo);

        glfwSetKeyCallback(window, key_callback_main_menu);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}