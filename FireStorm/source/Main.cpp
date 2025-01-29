#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <../../../Dependencies/glad/glad.h>
//#include <../../../Dependencies/glm/glm.hpp>
//#include <../../../Dependencies/glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>
#include <vector>

#include <time.h>

#include "../Buffers/Buffer.hpp"
#include "../Buffers/IndexBuffer.hpp"
#include "../Buffers/VertexArray.hpp"
#include "../Textures/Texture.hpp"
#include "../Buffers/Mesh.hpp"
#include "../Textures/Laser.hpp"
#include "../Textures/Enemy.hpp"
#include "../Utilities/Timer.hpp"
#include "../Shaders/Shader.hpp"
#include "../Camera/Camera.h"
//#include "../Math/maths.hpp"

#include "../Textures/roadSegment.hpp"
#include "../Textures/Car.hpp"
#include "../Data/coords.hpp"
#include "../Data/colours.hpp"

#include "../Utilities/Renderer_functions.hpp"
#include "../Utilities/GPU_enablement.hpp"

// Vendors
#define TINYOBJLOADER_IMPLEMENTATION
#include "vendor/tinyobjloader/tiny_obj_loader.h"

// Scenes
#include "../Scenes/main_screen.hpp"


#ifdef DEBUG_API
#else
    #define NDEBUG
#endif

#define what_is(x) std::cerr << #x << " is " << x << std::endl;

GLfloat terrain_vertices[] = {
    // Terrain
    -50.0f, 0.0f, -50.0f,
    -50.0f, 0.0f,  50.0f,
     50.0f, 0.0f,  50.0f,
     50.0f, 0.0f, -50.0f
};

GLfloat left_wall_vertices[] = {
    -50.0f, 0.0f, -50.0f,
    -50.0f, 5.0f, -50.0f,
    -45.0f, 5.0f, -50.0f,
    -45.0f, 0.0f, -50.0f,
};

/*
GLfloat terrain_vertices_2D[] = {
    // Terrain
    -50.0f, -50.0f,
    -50.0f,  50.0f,
     50.0f,  50.0f,
     50.0f, -50.0f
};
*/

GLuint terrain_indices[] =
{
    0, 1, 2,
    0, 2, 3,
};

GLuint terrain_indices_right[] =
{
    0, 1, 2,
    0, 2, 3
};

float texture_pos[] = {
    0.00f, 0.00f,
    0.00f, 0.25f,
    0.25f, 0.25f,
    0.25f, 0.00f
};

float texture_poz[] = {
    0.00f, 0.00f,
    0.00f, 0.20f,
    0.20f, 0.20f,
    0.20f, 0.00f
};

// angle of rotation
float angle = 0.0f;

// rotation axis
glm::vec3 axis(0.0f, 1.0f, 0.0f);

// rotation matrix
glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, axis);

glm::mat4 modelMatrix = glm::mat4(1.0f);

int width, height;
bool directions[4] {0};

void key_callback_WASD(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

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
    //std::cout << char(7);

    if (key == GLFW_KEY_A && action == GLFW_PRESS)
    {
        //angle += 0.5f;
        //rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, axis);
    }
    if (key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        //angle -= 0.5f;
        //rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, axis);
    }
}

void move_coords(float* texture_pos, int direction, float value) {
    // 0 - up
    // 1 - left
    // 2 - down
    // 3 - right
    
    switch (direction) 
    {
    case 0:
        texture_pos[0] += value;
        texture_pos[3] += value;
        texture_pos[6] += value;
        texture_pos[9] += value;
        texture_pos[12] += value;
        texture_pos[15] += value;
        texture_pos[18] += value;
        texture_pos[21] += value;
        break;
    case 1:
        texture_pos[2] -= value;
        texture_pos[5] -= value;
        texture_pos[8] -= value;
        texture_pos[11] -= value;
        texture_pos[14] -= value;
        texture_pos[17] -= value;
        texture_pos[20] -= value;
        texture_pos[23] -= value;
        break;
    case 2:
        texture_pos[0] -= value;
        texture_pos[3] -= value;
        texture_pos[6] -= value;
        texture_pos[9] -= value;
        texture_pos[12] -= value;
        texture_pos[15] -= value;
        texture_pos[18] -= value;
        texture_pos[21] -= value;
        break;
    case 3:
        texture_pos[2] += value;
        texture_pos[5] += value;
        texture_pos[8] += value;
        texture_pos[11] += value;
        texture_pos[14] += value;
        texture_pos[17] += value;
        texture_pos[20] += value;
        texture_pos[23] += value;
        break;
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
    window = glfwCreateWindow(640, 480, "3.0 BiTurbo inline6", NULL, NULL); 

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
    // Background
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

    Texture background_texture("Textures/background_duck.png");
    background_texture.bind();

    background_shader.uniform1i("texture1", 0);

    // Terrain
    float terrain_coord[] = { // although we might not need it
        0.00f, 0.00f,
        0.00f, 1.00f,
        1.00f, 1.00f,
        1.00f, 0.00f
    };

    GLuint terrain_indices[] = { 0, 1, 2,  0, 2, 3 };

    VertexArray terrain_sprite;
    Buffer* terrain_vbo1 = new Buffer(terrain_vertices, 4 * 3, 3);
    //Buffer* terrain_vbo1 = new Buffer(terrain_vertices_2D, 4 * 2, 2);
    //Buffer* terrain_vbo2 = new Buffer(color_green, 4 * 4, 4);
    Buffer* terrain_vbo2 = new Buffer(texture_poz, 4 * 2, 2);
    IndexBuffer terrain_ibo(terrain_indices, 6);

    terrain_sprite.addBuffer(terrain_vbo1, 0);
    //terrain_sprite.addBuffer(terrain_vbo2, 1); // color
    terrain_sprite.addBuffer(terrain_vbo2, 2); // texture coords

    terrain_sprite.bind();
    terrain_ibo.bind();

    Shader terrain_shader;
    //terrain_shader.createShader("Shaders/terrain_vert.shader", "Shaders/terrain_frag.shader");
    terrain_shader.createShader("Shaders/terrain_texture_vert.shader", "Shaders/terrain_texture_frag.shader");
    terrain_shader.bind();

    Texture terrain_texture("Textures/grass.png");
    //Texture terrain_texture("Textures/background_duck.png");
    terrain_texture.bind();
    terrain_shader.bind();

    terrain_shader.uniform1i("terrain_texture", 0);

    // Walls
    GLuint left_wall_indices[] = { 0, 1, 2,  0, 2, 3 };

    VertexArray left_wall_sprite;
    Buffer* left_wall_vbo1 = new Buffer(left_wall_vertices, 4 * 3, 3);
    Buffer* left_wall_vbo2 = new Buffer(texture_poz, 4 * 2, 2);
    IndexBuffer left_wall_ibo(left_wall_indices, 6);

    left_wall_sprite.addBuffer(left_wall_vbo1, 0);
    left_wall_sprite.addBuffer(left_wall_vbo2, 2); // texture coords

    left_wall_sprite.bind();
    left_wall_ibo.bind();

    Shader left_wall_shader;
    left_wall_shader.createShader("Shaders/terrain_texture_vert.shader", "Shaders/left_wall_texture_frag.shader");
    left_wall_shader.bind();

    Texture left_wall_texture("Textures/brick_wall.png");
    left_wall_texture.bind();
    left_wall_shader.bind();
    left_wall_shader.uniform1i("left_wall_texture", 0);

    /*
    -40.0f, 1.0f, -42.0f, -40.0f, 1.1f, -42.0f,
    -40.0f, 1.0f, -45.0f, -40.0f, 1.1f, -45.0f,
    -30.0f, 1.0f, -45.0f, -30.0f, 1.1f, -45.0f,
    -30.0f, 1.0f, -42.0f, -30.0f, 1.1f, -42.0f
    */

    // Custom mouse-following star
    float star_pos[] = {
        -1.00f, -1.00f,
        -1.00f,  1.00f,
         1.00f,  1.00f,
    };
    float star_pos2[] = {
        -1.00f, -1.00f,
         1.00f,  1.00f,
         1.00f, -1.00f
    };
    GLuint star_indices[] = { 0, 1, 2 };

    VertexArray star_sprite1, star_sprite2;
    Buffer* star_vbo0 = new Buffer(star_pos, 4 * 2, 2);
    Buffer* star_vbo1 = new Buffer(color_white, 4 * 4, 4);
    Buffer* star_vbo2 = new Buffer(star_pos2, 4 * 2, 2);
    Buffer* star_vbo3 = new Buffer(color_white, 4 * 4, 4);
    IndexBuffer star_ibo(star_indices, 3);

    star_sprite1.addBuffer(star_vbo0, 0);
    star_sprite1.addBuffer(star_vbo1, 1);
    star_sprite2.addBuffer(star_vbo2, 0);
    star_sprite2.addBuffer(star_vbo3, 1);

    star_sprite1.bind();
    star_ibo.bind();

    Shader star_shader;
    star_shader.createShader("Shaders/star_vert_color.shader", "Shaders/star_frag_color.shader");
    star_shader.bind();

    // Camera
    //Camera camera(640, 480, glm::vec3(0.0f, 0.0f, 2.0f));
    Camera camera(640, 480, glm::vec3(-37.5f, 2.1f, -44.2f));

    Timer timer;
    float current_time(0.0f);
    unsigned int frames(0);

    timer.reset();

    //Main screen
    main_screen(window);

    GLfloat camera_mat4[16];

    while (!glfwWindowShouldClose(window))
    {
        //glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.7f, 0.9f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

        // Handles camera inputs
        camera.Inputs(window);
        // Updates and exports the camera matrix to the Vertex Shader
        camera.updateMatrix(45.0f, 0.1f, 100.0f);

        //car.updateMatrix(modelMatrix);

        // Background render
        /*
        background_texture.bind();
        background_shader.bind();
        drawCall_quad(background_sprite, background_ibo);
        background_texture.unbind();
        */

        // Terrain Render
        terrain_sprite.bind();
        terrain_ibo.bind();
        terrain_texture.bind();
        terrain_shader.bind();
        camera.Matrix(terrain_shader, "camMatrix");
        drawCall_quad(terrain_sprite, terrain_ibo);

        // Left Wall
        left_wall_sprite.bind();
        left_wall_ibo.bind();
        left_wall_texture.bind();
        left_wall_shader.bind();
        camera.Matrix(left_wall_shader, "camMatrix");
        drawCall_quad(left_wall_sprite, left_wall_ibo);

        /*
        car.bind();
        camera.Matrix(car.car_shader, "camMatrix");
        drawCall_cube(car.getSprite(), car.getIbo());
        */

        // Star
        /*
        star_shader.bind();
        star_shader.uniform2f_mouse_pos(window, "light_pos");
        //drawCall_quad(star_sprite1, star_ibo);
        drawCall_triangle(star_sprite1, star_ibo);
        drawCall_triangle(star_sprite2, star_ibo);
        */

        glfwSetKeyCallback(window, key_callback_WASD);

        glfwSwapBuffers(window);
        glfwPollEvents();

        // Resize event handler
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        
        // FPS counter system
        ++frames;
        if (timer.elapsed() - current_time >= 1.0f) {
            current_time  += 1.0f;
            std::cout << frames << "FPS" << std::endl;
            frames = 0;
        }
    }

    background_shader.unbind();
    star_shader.unbind();

    glfwTerminate();
    return 0;
}