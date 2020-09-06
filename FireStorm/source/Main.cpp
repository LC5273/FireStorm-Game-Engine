#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>

#include "../Buffers/Buffer.hpp"
#include "../Buffers/IndexBuffer.hpp"
#include "../Buffers/VertexArray.hpp"
#include "../Utilities/Renderer.h"
#include "../Utilities/Texture.hpp"
#include "../Shaders/Shader.hpp"
#include "../Math/maths.hpp"

#include "../Utilities/Renderer_functions.hpp"


#ifdef DEBUG_API
#else
    #define NDEBUG
#endif

#define what_is(x) std::cerr << #x << " is " << x << std::endl;

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

void key_callback_test(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
        std::cout << "E\n";
}

void move_coords(float* texture_pos, int direction, float value) {
    // 0 - up
    // 1 - left
    // 2 - down
    // 3 - right
    
    switch (direction) 
    {
    case 0:
        texture_pos[1] += value;
        texture_pos[3] += value;
        texture_pos[5] += value;
        texture_pos[7] += value;
        break;
    case 1:
        texture_pos[0] -= value;
        texture_pos[2] -= value;
        texture_pos[4] -= value;
        texture_pos[6] -= value;
        break;
    case 2:
        texture_pos[1] -= value;
        texture_pos[3] -= value;
        texture_pos[5] -= value;
        texture_pos[7] -= value;
        break;
    case 3:
        texture_pos[0] += value;
        texture_pos[2] += value;
        texture_pos[4] += value;
        texture_pos[6] += value;
        break;
    }
}

bool directions[4] = {0};

void key_callback_WASD(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_W) {
        if (action == GLFW_PRESS)
            directions[0] = 1;
        else if (action == GLFW_RELEASE)
            directions[0] = 0;
    }
    else
        if (key == GLFW_KEY_A) {
            if (action == GLFW_PRESS)
                directions[1] = 1;
            else if (action == GLFW_RELEASE)
                directions[1] = 0;
        }
        else
            if (key == GLFW_KEY_S) {
                if (action == GLFW_PRESS)
                    directions[2] = 1;
                else if (action == GLFW_RELEASE)
                    directions[2] = 0;
            }
            else
                if (key == GLFW_KEY_D) {
                    if (action == GLFW_PRESS)
                        directions[3] = 1;
                    else if (action == GLFW_RELEASE)
                        directions[3] = 0;
                }

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        std::cout << char(7);
}

void pos_update() 
{
    if(directions[0]) move_coords(texture_pos, 0, 0.0001);
    if(directions[1]) move_coords(texture_pos, 1, 0.0001);
    if(directions[2]) move_coords(texture_pos, 2, 0.0001);
    if(directions[3]) move_coords(texture_pos, 3, 0.0001);
}


int main()
{
    /* Initializing GLFW */
    if (!glfwInit()) {
        std::cout << "GLFW initialization failed!\n";
        return -1;
    }

    /* Create a window */
    GLFWwindow* window;
    window = glfwCreateWindow(640, 480, "Application", NULL, NULL); 

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    /* Initializing GLEW */
    GLenum err = glewInit(); 
    if (err != GLEW_OK) {
        std::cout << "GLEW initialization failed!\n";
        return -1;
    }

    float positionsINIT[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    float position[6] = {
        -0.75f, -0.75f,
         0.00f,  0.75f,
         0.75f, -0.75f
    };

    float position1[12] = {
        0.75f,  0.75f,
        0.00f,  0.75f,
        0.75f, -0.75f,

        -0.75f, -0.75f,
         0.00f,  0.75f,
         0.75f, -0.75f
    };

    float positions1[] = {
        -0.75f, -0.75f,
         0.00f,  0.75f,
         0.75f, -0.75f
    };

    float positions2[] = {
        0.75f,  0.75f,
        0.00f,  0.75f,
        0.75f, -0.75f,
    };

    GLuint indices[] = { 0, 1, 2,  3, 4, 5 };
    GLuint texture_indices[] = { 0, 1, 2,  0, 2, 3 };
    GLuint indices1[] = { 0, 1, 2 };
    GLuint indices2[] = { 3, 4, 5 };

    float colorA[] {
        0.8f, 0.5f, 1.0f, 1.0f,
        0.8f, 0.5f, 1.0f, 1.0f,
        0.8f, 0.5f, 1.0f, 1.0f
    };

    float colorB[] {
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f
    };
#if 0
    VertexArray sprite1, sprite2;
    Buffer* vbo11 = new Buffer(positions1, 2 * 6, 2);
    Buffer* vbo12 = new Buffer(colorA, 3 * 4, 4);
    Buffer* vbo21 = new Buffer(positions2, 2 * 6, 2);
    Buffer* vbo22 = new Buffer(colorB, 3 * 4, 4);
    IndexBuffer ibo(indices, 6);

    sprite1.addBuffer(vbo11, 0);
    sprite1.addBuffer(vbo12, 1);
    sprite2.addBuffer(vbo21, 0);
    sprite2.addBuffer(vbo22, 1);

    //sprite1.bind();
    //ibo.bind();

    //Shader s("Shaders/vert_color.shader", "Shaders/frag_color.shader");
    Shader s;
    s.createShader("Shaders/vert_color.shader", "Shaders/frag_color.shader");
    s.bind();
#endif

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Background
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
    Buffer* vbo11 = new Buffer(background_pos, 8 * 2, 2);
    Buffer* vbo21 = new Buffer(background_coord, 8 * 2, 2);
    IndexBuffer background_ibo(background_indices, 6);

    background_sprite.addBuffer(vbo11, 0);
    background_sprite.addBuffer(vbo21, 2);

    background_sprite.bind();
    background_ibo.bind();


    Shader background_shader;
    background_shader.createShader("Shaders/vert_background.shader", "Shaders/frag_background.shader");
    background_shader.bind();

    Texture background_texture("Textures/background.png");
    background_texture.bind();

    background_shader.uniform1i(window, "texture1", 0);
    //

    VertexArray spaceship_sprite;
    Buffer* spaceship_coord_vbo1 = new Buffer(texture_pos, 8 * 2, 2);
    Buffer* spaceship_coord_vbo2 = new Buffer(texture_poz, 8 * 2, 2);
    IndexBuffer spaceship_ibo(texture_indices, 6);

    spaceship_sprite.addBuffer(spaceship_coord_vbo1, 0);
    spaceship_sprite.addBuffer(spaceship_coord_vbo2, 2);

    spaceship_sprite.bind();
    spaceship_ibo.bind();


    Shader spaceship_shader;
    spaceship_shader.createShader("Shaders/vert_texture.shader", "Shaders/frag_texture.shader");
    spaceship_shader.bind();

    Texture spaceship_texture("Textures/spaceship.png");
    spaceship_texture.bind();

    spaceship_shader.uniform1i(window, "texture1", 0);
    
    //double x, y;
    //int width, height;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT); 
        //glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
#if 0
        s.uniform2f_mouse_pos(window, "light_pos");

        sprite1.bind();
        ibo.bind();
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
        ibo.unbind();
        sprite1.unbind();
        
        sprite2.bind();
        ibo.bind();
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
        ibo.unbind();
        sprite2.unbind();
#endif
        spaceship_coord_vbo1->update(texture_pos, 8 * 2);

        background_texture.bind();
        background_shader.bind();
        drawCall_quad(background_sprite, background_ibo);

        spaceship_texture.bind();
        spaceship_shader.bind();
        drawCall_quad(spaceship_sprite, spaceship_ibo);

        glfwSetKeyCallback(window, key_callback_WASD);
        pos_update();

        glfwSwapBuffers(window);
        glfwPollEvents();

        /*
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        */
    }

    background_shader.unbind();
    spaceship_shader.unbind();

    glfwTerminate();
    return 0;
}