#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>

#include "../Buffers/Buffer.h"
#include "../Buffers/IndexBuffer.h"
#include "../Buffers/VertexArray.h"
#include "../Utilities/Renderer.h"
#include "../Utilities/EventSystem.h"
#include "../Utilities/Texture.h"
#include "../Shaders/Shader.h"
#include "../Math/maths.h"


#ifdef DEBUG_API
#else
    #define NDEBUG
#endif

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

void key_callback1(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
        std::cout << "E\n";
}

void move_coords(float* texture_pos, int direction, float value) {
    // 0 - up
    // 1 - right
    // 2 - down
    // 3 - left
    
    switch (direction) 
    {
    case 0:
        texture_pos[1] += value;
        texture_pos[3] += value;
        texture_pos[5] += value;
        texture_pos[7] += value;
        break;
    case 1:
        texture_pos[0] += value;
        texture_pos[2] += value;
        texture_pos[4] += value;
        texture_pos[6] += value;
        break;
    case 2:
        texture_pos[1] -= value;
        texture_pos[3] -= value;
        texture_pos[5] -= value;
        texture_pos[7] -= value;
        break;
    case 3:
        texture_pos[0] -= value;
        texture_pos[2] -= value;
        texture_pos[4] -= value;
        texture_pos[6] -= value;
        break;
    }
}

void key_callback_WASD(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_W) {
        if (action == GLFW_PRESS)
            move_coords(texture_pos, 0, 0.01);
        else if (action == GLFW_RELEASE);
    }
    else
        if (key == GLFW_KEY_A) {
            if (action == GLFW_PRESS)
                move_coords(texture_pos, 1, 0.01);
            else if (action == GLFW_RELEASE);
        }
        else
            if (key == GLFW_KEY_S) {
                if (action == GLFW_PRESS)
                    move_coords(texture_pos, 2, 0.01);
                else if (action == GLFW_RELEASE);
            }
            else
                if (key == GLFW_KEY_D) {
                    if (action == GLFW_PRESS)
                        move_coords(texture_pos, 3, 0.01);
                    else if (action == GLFW_RELEASE);
                }
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

    float colorA[]{
        0.8f, 0.5f, 1.0f, 1.0f,
        0.8f, 0.5f, 1.0f, 1.0f,
        0.8f, 0.5f, 1.0f, 1.0f
    };

    float colorB[]{
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

    /*
    VertexArray sprite1, sprite2;
    Buffer* vbo11 = new Buffer(texture_position1, 6 * 2, 2);
    Buffer* vbo12 = new Buffer(texture_position2, 6 * 2, 2);
    Buffer* vbo21 = new Buffer(texture_position3, 6 * 2, 2);
    Buffer* vbo22 = new Buffer(texture_position4, 6 * 2, 2);
    IndexBuffer ibo(texture_indices, 6);

    sprite1.addBuffer(vbo11, 0);
    sprite1.addBuffer(vbo21, 2);
    sprite2.addBuffer(vbo12, 0);
    sprite2.addBuffer(vbo22, 2);

    sprite1.bind();
    ibo.bind();
    */

    VertexArray sprite;
    Buffer* vbo1 = new Buffer(texture_pos, 8 * 2, 2);
    Buffer* vbo2 = new Buffer(texture_poz, 8 * 2, 2);
    IndexBuffer ibo(texture_indices, 6);

    sprite.addBuffer(vbo1, 0);
    sprite.addBuffer(vbo2, 2);

    sprite.bind();
    ibo.bind();


    Shader s;
    s.createShader("Shaders/vert_texture.shader", "Shaders/frag_texture.shader");
    s.bind();

    Texture texture1("Textures/spaceship0.png");
    texture1.bind();

    s.uniform1i(window, "texture1", 0);

    //mat4 pos = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    ////std::cout << pos;
    //float z[16];
    //pos.elements(z);

    ////glUniformMatrix4fv(glGetUniformLocation(shader, "pr_matrix"), 1, GL_FALSE, z);
    
    double x, y;
    int width, height;

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
        //Buffer* vbo = new Buffer(texture_pos, 8 * 2, 2);
        //sprite.addBuffer(vbo, 0);


        sprite.bind();
        ibo.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        ibo.unbind();
        sprite.unbind();

        glfwSetKeyCallback(window, key_callback_WASD);

        glfwSwapBuffers(window);
        glfwPollEvents();

        //delete [] vbo;
        /*
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        */
    }

    s.unbind();

    glfwTerminate();
    return 0;
}