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

double xMousePos, yMousePos;

void mouse_callback_main_menu(GLFWwindow* window, int key, int scancode, int action) {
    if (key == GLFW_MOUSE_BUTTON_1 && action == GLFW_RELEASE)
        if ((640 / 2 - 320 / 5 < xMousePos && 640 / 2 + 320 / 5 > xMousePos) && (480 / 2 - 240 * 2 / 5 > yMousePos && 480 / 2 - 240 * 3 / 5 < yMousePos))
        exit_main_s = true;
}

void mouse_pos_callback_main_menu(GLFWwindow* window, double xPos, double yPos) {
    xMousePos = xPos;
    yMousePos = yPos;

    //std::cout << xMousePos << " : " << yMousePos << std::endl;
}

void main_screen(GLFWwindow* window) {
    if (!window)
    {
        std::cout << "Main screen window error";
        glfwTerminate();
    }

    // Initialization

    // Background texture

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

    Texture background_texture("Textures/main_menu/main_menu_background.png");
    background_texture.bind();

    background_shader.uniform1i("texture1", 0);

    // Play button

    float play_button_pos[] = {
        -0.20f, 0.40f,
        -0.20f, 0.60f,
         0.20f, 0.60f,
         0.20f, 0.40f
    };
    float play_button_coord[] = {
        0.00f, 0.00f,
        0.00f, 1.00f,
        1.00f, 1.00f,
        1.00f, 0.00f
    };

    GLuint play_button_indices[] = { 0, 1, 2,  0, 2, 3 };

    VertexArray play_button_sprite;
    Buffer* play_button_vbo1 = new Buffer(play_button_pos, 8 * 2, 2);
    Buffer* play_button_vbo2 = new Buffer(play_button_coord, 8 * 2, 2);
    IndexBuffer play_button_ibo(play_button_indices, 6);

    play_button_sprite.addBuffer(play_button_vbo1, 0);
    play_button_sprite.addBuffer(play_button_vbo2, 2);

    play_button_sprite.bind();
    play_button_ibo.bind();

    Shader play_button_shader;
    play_button_shader.createShader("Shaders/vert_background.shader", "Shaders/frag_background.shader");
    play_button_shader.bind();

    Texture play_button_texture("Textures/main_menu/play_raw_cut.png");
    Texture play_button_glow_texture("Textures/main_menu/play_glow_cut.png");
    play_button_texture.bind();

    play_button_shader.uniform1i("texture1", 0);

    while (!glfwWindowShouldClose(window) && !exit_main_s)
    {
        background_texture.bind();
        background_shader.bind();
        drawCall_quad(background_sprite, background_ibo);

        if ( ( 640 / 2 - 320 / 5 < xMousePos && 640 / 2 + 320 / 5 > xMousePos ) && ( 480 / 2 - 240 * 2 / 5 > yMousePos && 480 / 2 - 240 * 3 / 5 < yMousePos ) )
            play_button_glow_texture.bind();
        else
            play_button_texture.bind();
        play_button_shader.bind();
        drawCall_quad(play_button_sprite, play_button_ibo);

        glfwSetMouseButtonCallback(window, mouse_callback_main_menu);
        //glfwSetCursorPosCallback(window, mouse_pos_callback_main_menu);
        glfwGetCursorPos(window, &xMousePos, &yMousePos);
        //std::cout << xMousePos << " : " << yMousePos << std::endl;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}