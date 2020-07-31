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
#include "../Shaders/Shader.h"
#include "../Math/maths.h"

#include "../vendor/stb_image/stb_image.h"


#ifdef DEBUG_API
#else
    #define NDEBUG
#endif

void key_callback1(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
        std::cout << "E\n";
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

    /*
    unsigned int vbo, vbo1;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    */

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
    /*
    //std::stringstream s1 = file2string("Shaders/vert1.shader");
    //std::stringstream s2 = file2string("Shaders/frag1.shader");
    std::stringstream s1 = file2string("Shaders/vert_color.shader");
    std::stringstream s2 = file2string("Shaders/frag_color.shader");
    unsigned int shader = CreateShader(s1.str(), s2.str());
    glUseProgram(shader);
    */

    mat4 pos = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    //std::cout << pos;
    float z[16];
    pos.elements(z);

    //glUniformMatrix4fv(glGetUniformLocation(shader, "pr_matrix"), 1, GL_FALSE, z);
    
    double x, y;
    int width, height;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT); 
        //glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

        //glfwGetCursorPos(window, &x, &y);
        //glUniform2f(glGetUniformLocation(shader, "light_pos"), (float)(x / 320.0f - 1.0f), (float)(1.0f - y / 240.0f));
        s.uniform2f(window, "light_pos");

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

        glfwSetKeyCallback(window, key_callback1);

        glfwSwapBuffers(window);
        glfwPollEvents();

        /*
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        */
    }

    s.unbind();

    glfwTerminate();
    return 0;
}