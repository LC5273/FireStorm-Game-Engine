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

#include "../Scenes/main_screen.hpp"


#ifdef DEBUG_API
#else
    #define NDEBUG
#endif

#define what_is(x) std::cerr << #x << " is " << x << std::endl;

GLfloat terrain_vertices[] = {
    // Terrain
    -50.0f, 0.0f, -50.0f, -50.0f, 1.0f, -50.0f,
    -50.0f, 0.0f,  50.0f, -50.0f, 1.0f, 50.0f,
     50.0f, 0.0f,  50.0f, 50.0f, 1.0f, 50.0f,
     50.0f, 0.0f, -50.0f, 50.0f, 1.0f, -50.0f
};

GLfloat road_vertices[] = {
    // Terrain
    -30.0f, 1.0f, -20.0f, -30.0f, 1.1f, -20.0f,
    -30.0f, 1.0f,  20.0f, -30.0f, 1.1f,  20.0f,
     30.0f, 1.0f,  20.0f,  30.0f, 1.1f,  20.0f,
     30.0f, 1.0f, -20.0f,  30.0f, 1.1f, -20.0f
};

GLfloat terrain_vertices_lower[] = {
    // Terrain
    -0.50f, 0.0f, -0.50f, -0.50f, 0.10f, -0.50f,
    -0.50f, 0.0f,  0.50f, -0.50f, 0.10f, 0.50f,
     0.50f, 0.0f,  0.50f, 0.50f, 0.10f, 0.50f,
     0.50f, 0.0f, -0.50f, 0.50f, 0.10f, -0.50f
};

GLuint terrain_indices[] =
{
    0, 1, 2,
    0, 2, 3,
    0, 4, 7,
    0, 7, 3,
    3, 7, 6,
    3, 6, 2,
    2, 6, 5,
    2, 5, 1,
    1, 5, 4,
    1, 4, 0,
    4, 5, 6,
    4, 6, 7
};

GLuint terrain_indices_right[] =
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

// angle of rotation
float angle = 0.0f;

// rotation axis
glm::vec3 axis(0.0f, 1.0f, 0.0f);

// rotation matrix
glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, axis);

glm::mat4 modelMatrix = glm::mat4(1.0f);
glm::vec3 centerOfObject = glm::vec3(-46.0f, 1.05f, -37.0f); // wrong

int width, height;
bool directions[4] {0};

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

void pos_update(Car& car, float* texture_coord)
{
    if (directions[0]) move_coords(texture_coord, 0, 0.0005);
    if (directions[1]) {
        angle += 0.0001f;
        rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, axis);

        float x = (texture_coord[0] + texture_coord[12]) / 2;
        float y = (texture_coord[1] + texture_coord[5]) / 2;
        float z = (texture_coord[2] + texture_coord[8]) / 2;

        centerOfObject = glm::vec3(x, y, z);
        //std::cout << x << ' ' << y << ' ' << z << std::endl;
        //modelMatrix = glm::mat4(1.0f);
        
        // Translate the object to the origin
        glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), -centerOfObject);
        modelMatrix = modelMatrix * translationMatrix;

        // Perform the rotation
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));
        modelMatrix = modelMatrix * rotationMatrix;

        // Translate the object back to its original position
        glm::mat4 translationMatrixBack = glm::translate(glm::mat4(1.0f), centerOfObject);
        modelMatrix = modelMatrix * translationMatrix;
        
        modelMatrix = translationMatrixBack * rotationMatrix * translationMatrix;

        //glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));
        //glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(-5.0f), glm::vec3(x, y, z));
        //modelMatrix = rotation * modelMatrix;
        //modelMatrix = modelMatrix * rotation;
    }
    if (directions[2]) move_coords(texture_coord, 2, 0.0005);
    if (directions[3]) {
        angle -= 0.0001f;
        rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, axis);

        float x = (texture_coord[0] + texture_coord[12]) / 2;
        float y = (texture_coord[1] + texture_coord[5]) / 2;
        float z = (texture_coord[2] + texture_coord[8]) / 2;

        centerOfObject = glm::vec3(x, y, z);
        //std::cout << x << ' ' << y << ' ' << z << std::endl;

        // Translate the object to the origin
        glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), -centerOfObject);
        modelMatrix = modelMatrix * translationMatrix;

        // Perform the rotation
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));
        modelMatrix = modelMatrix * rotationMatrix;

        // Translate the object back to its original position
        glm::mat4 translationMatrixBack = glm::translate(glm::mat4(1.0f), centerOfObject);
        modelMatrix = modelMatrix * translationMatrix;

        modelMatrix = translationMatrixBack * rotationMatrix * translationMatrix;

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j);
                //std::cout << modelMatrix[i][j] << ' ';
        glm::vec4 finalcoord = glm::vec4(0.0f);
        finalcoord.x = texture_coord[0];
        finalcoord.y = texture_coord[1];
        finalcoord.z = texture_coord[2];

        finalcoord = finalcoord * modelMatrix;
        for (int i = 0; i < 4; ++i)
            std::cout << finalcoord[i] << ' ';
        std::cout << std::endl; // * with model anc update coords car

        //glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));
        //glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(-5.0f), glm::vec3(x, y, z));
        //modelMatrix = rotation * modelMatrix;
        //modelMatrix = modelMatrix * rotation;
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

    float color_green[]{
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f
    };

    float color_grey1[]{
        0.0f, 0.1f, 0.2f, 1.0f,
        0.0f, 0.1f, 0.2f, 1.0f,
        0.0f, 0.1f, 0.2f, 1.0f,
        0.0f, 0.1f, 0.2f, 1.0f,
        0.0f, 0.1f, 0.2f, 1.0f,
        0.0f, 0.1f, 0.2f, 1.0f,
        0.0f, 0.1f, 0.2f, 1.0f,
        0.0f, 0.1f, 0.2f, 1.0f
    };

    float color_brown[] { //3rd should be 0
        0.6f, 0.3f, 0.1f, 1.0f,
        0.6f, 0.3f, 0.1f, 1.0f,
        0.6f, 0.3f, 0.1f, 1.0f
    };

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

    //GLuint terrain_indices[] = { 0, 1, 2,  1, 2, 3 };
    GLuint terrain_indices[] = { 0, 2, 4,  2, 4, 6};

    VertexArray terrain_sprite;
    Buffer* terrain_vbo1 = new Buffer(terrain_vertices, 8 * 3, 3);
    Buffer* terrain_vbo2 = new Buffer(color_green, 8 * 4, 4);
    IndexBuffer terrain_ibo(terrain_indices_right, 36);

    terrain_sprite.addBuffer(terrain_vbo1, 0);
    terrain_sprite.addBuffer(terrain_vbo2, 1);

    terrain_sprite.bind();
    terrain_ibo.bind();

    Shader terrain_shader;
    terrain_shader.createShader("Shaders/terrain_vert.shader", "Shaders/terrain_frag.shader");
    terrain_shader.bind();

    // Road
    std::vector<roadSegment> road;
    road.reserve(roadSegments);

    roadSegment road1(roadSegment1);
    roadSegment road2(roadSegment2);
    roadSegment road3(roadSegment3);
    roadSegment road4(roadSegment4);
    roadSegment road5(roadSegment5);
    roadSegment road6(roadSegment6);
    roadSegment road7(roadSegment7);
    roadSegment road8(roadSegment8);
    roadSegment road9(roadSegment9);
    roadSegment road10(roadSegment10);
    roadSegment road11(roadSegment11);
    roadSegment road12(roadSegment12);
    roadSegment road13(roadSegment13);

    Car car(carCoord);

    //road.emplace_back(road1);

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

        //car.updateMatrix(rotationMatrix);
        car.updateMatrix(modelMatrix);

        // Background render
        /*
        background_texture.bind();
        background_shader.bind();
        drawCall_quad(background_sprite, background_ibo);
        background_texture.unbind();
        */

        // Terrain Render
        terrain_shader.bind();
        camera.Matrix(terrain_shader, "camMatrix");
        drawCall_cube(terrain_sprite, terrain_ibo);

        // Road
        road1.bind();
        camera.Matrix(road1.road_shader, "camMatrix");
        drawCall_cube(road1.getSprite(), road1.getIbo());

        road2.bind();
        camera.Matrix(road2.road_shader, "camMatrix");
        drawCall_cube(road2.getSprite(), road2.getIbo());

        road3.bind();
        camera.Matrix(road3.road_shader, "camMatrix");
        drawCall_cube(road3.getSprite(), road3.getIbo());

        road4.bind();
        camera.Matrix(road4.road_shader, "camMatrix");
        drawCall_cube(road4.getSprite(), road4.getIbo());

        road5.bind();
        camera.Matrix(road5.road_shader, "camMatrix");
        drawCall_cube(road5.getSprite(), road5.getIbo());

        road6.bind();
        camera.Matrix(road6.road_shader, "camMatrix");
        drawCall_cube(road6.getSprite(), road6.getIbo());

        road7.bind();
        camera.Matrix(road7.road_shader, "camMatrix");
        drawCall_cube(road7.getSprite(), road7.getIbo());

        road8.bind();
        camera.Matrix(road8.road_shader, "camMatrix");
        drawCall_cube(road8.getSprite(), road8.getIbo());

        road9.bind();
        camera.Matrix(road9.road_shader, "camMatrix");
        drawCall_cube(road9.getSprite(), road9.getIbo());

        road10.bind();
        camera.Matrix(road10.road_shader, "camMatrix");
        drawCall_cube(road10.getSprite(), road10.getIbo());

        road11.bind();
        camera.Matrix(road11.road_shader, "camMatrix");
        drawCall_cube(road11.getSprite(), road11.getIbo());

        road12.bind();
        camera.Matrix(road12.road_shader, "camMatrix");
        drawCall_cube(road12.getSprite(), road12.getIbo());

        road13.bind();
        camera.Matrix(road10.road_shader, "camMatrix");
        drawCall_cube(road10.getSprite(), road10.getIbo());

        car.bind();
        camera.Matrix(car.car_shader, "camMatrix");
        drawCall_cube(car.getSprite(), car.getIbo());
        // Star
        /*
        star_shader.bind();
        star_shader.uniform2f_mouse_pos(window, "light_pos");
        //drawCall_quad(star_sprite1, star_ibo);
        drawCall_triangle(star_sprite1, star_ibo);
        drawCall_triangle(star_sprite2, star_ibo);
        */

        glfwSetKeyCallback(window, key_callback_WASD);
        pos_update(car, car.coord);
        car.updateCoordVbo();

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