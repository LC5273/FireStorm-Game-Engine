#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <utility>

float color_white[]{
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f
};

float color_red[]{
    1.0f, 0.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 0.0f, 1.0f
};

float color_green[]{
    0.0f, 1.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f, 1.0f,
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

float color_brown[]{ //3rd should be 0
    0.6f, 0.3f, 0.1f, 1.0f,
    0.6f, 0.3f, 0.1f, 1.0f,
    0.6f, 0.3f, 0.1f, 1.0f
};