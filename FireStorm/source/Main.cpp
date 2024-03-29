#include <GL/glew.h>
#include <GLFW/glfw3.h>

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
#include "../Math/maths.hpp"

#include "../Utilities/Renderer_functions.hpp"
#include "../Utilities/GPU_enablement.hpp"

#include "../Scenes/main_screen.hpp"


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
bool movement = false;

std::vector<Laser> projectiles;
std::vector<Enemy> enemy;

int width, height;

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
        if (action == GLFW_PRESS) {
            directions[0] = 1;
            
            texture_pos[0] -= 0.03f;
            texture_pos[2] -= 0.03f;
            texture_pos[4] += 0.03f;
            texture_pos[6] += 0.03f;
            
            texture_pos[1] -= 0.10f;
            texture_pos[7] -= 0.10f;

            movement = true;
        }
        else if (action == GLFW_RELEASE) {
            directions[0] = 0;
            
            texture_pos[0] += 0.03f;
            texture_pos[2] += 0.03f;
            texture_pos[4] -= 0.03f;
            texture_pos[6] -= 0.03f;
            
            texture_pos[1] += 0.10f;
            texture_pos[7] += 0.10f;

            movement = false;
        }
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

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        Laser laser(texture_pos, 0.02f, 0.15f);
        projectiles.push_back(laser);
    }
        //std::cout << char(7);
}

void render_projectiles(std::vector<Laser>& projectiles, std::vector<Enemy>& enemy) {
    for (int i = 0; i < projectiles.size(); ++i) {
        projectiles[i].travel();
        projectiles[i].bind();
        drawCall_quad(projectiles[i].getSprite(), projectiles[i].get_ibo());

        for(int j = 0; j < enemy.size(); ++j) {
            if (projectiles[i].collision(enemy[j].position)) {
                projectiles.erase(projectiles.begin() + i);
                enemy.erase(enemy.begin() + j);
            }
            /*
            else if (!projectiles[i].valid()) {
                projectiles.erase(projectiles.begin() + i);
                std::cout << "laser deleted";
            }
            */
        }
        if (i < projectiles.size() && !projectiles[i].valid()) {
            projectiles.erase(projectiles.begin() + i);
        }
    }
}

void render_enemies(const std::vector<Enemy>& enemy) {
    for (int i(0); i < enemy.size(); ++i) {
        enemy[i].bind();
        drawCall_quad(enemy[i].enemy_sprite, enemy[i].enemy_ibo);
    }
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

    float color_white[] {
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f
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
    background_texture.bind();

    background_shader.uniform1i("texture1", 0);
    
    //Spaceship
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

    Texture spaceship_static_texture("Textures/spaceship.png");
    Texture spaceship_dynamic_texture("Textures/spaceship_dynamic.png");

    spaceship_shader.uniform1i("texture1", 0);

    //Custom mouse-following star

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

    //double x, y;
    //int width, height;

    float p[8] = {
        0.50f, 0.50f,
        0.50f, 0.85f,
        0.75f, 0.85f,
        0.75f, 0.50f
    };

    float p2[8] = {
        0.20f, 0.50f,
        0.20f, 0.85f,
        0.45f, 0.85f,
        0.45f, 0.50f
    };

    Enemy e(p), e2(p2);
    e.bind();
    enemy.push_back(e);
    e2.bind();
    enemy.push_back(e2);

    Timer timer;
    float current_time(0.0f);
    unsigned int frames(0);

    timer.reset();

    //Main screen
    main_screen(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        //glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

        spaceship_coord_vbo1->update(texture_pos, 8 * 2, 2);

        background_texture.bind();
        background_shader.bind();
        drawCall_quad(background_sprite, background_ibo);

        if (!movement)
            spaceship_static_texture.bind();
        else
            spaceship_dynamic_texture.bind();

        spaceship_shader.bind();
        drawCall_quad(spaceship_sprite, spaceship_ibo);
        
        
        star_shader.bind();
        star_shader.uniform2f_mouse_pos(window, "light_pos");
        //drawCall_quad(star_sprite1, star_ibo);
        drawCall_triangle(star_sprite1, star_ibo);
        drawCall_triangle(star_sprite2, star_ibo);

        render_enemies(enemy);
        render_projectiles(projectiles, enemy);

        glfwSetKeyCallback(window, key_callback_WASD);
        pos_update();

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
    spaceship_shader.unbind();
    star_shader.unbind();

    glfwTerminate();
    return 0;
}