#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <utility>

// Road Coords

GLint roadSegments = 4;

GLfloat carCoord[] {
    -37.0f, 1.1f, -44.5f, -37.0f, 1.5f, -44.5f,
    -37.0f, 1.1f, -44.0f, -37.0f, 1.5f, -44.0f,
    -36.0f, 1.1f, -44.0f, -36.0f, 1.5f, -44.0f,
    -36.0f, 1.1f, -44.5f, -36.0f, 1.5f, -44.5f
};

GLfloat roadSegment1[] = {
    -40.0f, 1.0f, -42.0f, -40.0f, 1.1f, -42.0f,
    -40.0f, 1.0f, -45.0f, -40.0f, 1.1f, -45.0f,
    -30.0f, 1.0f, -45.0f, -30.0f, 1.1f, -45.0f,
    -30.0f, 1.0f, -42.0f, -30.0f, 1.1f, -42.0f
};

GLfloat roadSegment2[] = {
    -30.0f, 1.0f, -42.0f, -30.0f, 1.1f, -42.0f,
    -30.0f, 1.0f, -45.0f, -30.0f, 1.1f, -45.0f,
    -20.0f, 1.0f, -40.0f, -20.0f, 1.1f, -40.0f,
    -20.0f, 1.0f, -37.0f, -20.0f, 1.1f, -37.0f
};

GLfloat roadSegment3[] = {
    -20.0f, 1.0f, -37.0f, -20.0f, 1.1f, -37.0f,
    -20.0f, 1.0f, -40.0f, -20.0f, 1.1f, -40.0f,
    -10.0f, 1.0f, -40.0f, -10.0f, 1.1f, -40.0f,
    -10.0f, 1.0f, -38.0f, -10.0f, 1.1f, -38.0f
};

GLfloat roadSegment4[] = {
    -10.0f, 1.0f, -38.0f, -10.0f, 1.1f, -38.0f,
    -10.0f, 1.0f, -40.0f, -10.0f, 1.1f, -40.0f,
    6.0f, 1.0f, -35.0f, 6.0f, 1.1f, -35.0f,
    6.0f, 1.0f, -33.0f, 6.0f, 1.1f, -33.0f
};

GLfloat roadSegment5[] = {
    6.0f, 1.0f, -33.0f, 6.0f, 1.1f, -33.0f,
    6.0f, 1.0f, -35.0f, 6.0f, 1.1f, -35.0f,
    21.0f, 1.0f, -31.0f, 21.0f, 1.1f, -31.0f,
    21.0f, 1.0f, -29.0f, 21.0f, 1.1f, -29.0f
};

GLfloat roadSegment6[] = {
    21.0f, 1.0f, -29.0f, 21.0f, 1.1f, -29.0f,
    21.0f, 1.0f, -31.0f, 21.0f, 1.1f, -31.0f,
    32.0f, 1.0f, -20.0f, 32.0f, 1.1f, -20.0f,
    30.0f, 1.0f, -20.0f, 30.0f, 1.1f, -20.0f
};

GLfloat roadSegment7[] = {
    30.0f, 1.0f, -20.0f, 30.0f, 1.1f, -20.0f,
    32.0f, 1.0f, -20.0f, 32.0f, 1.1f, -20.0f,
    34.0f, 1.0f, 7.0f, 34.0f, 1.1f, 7.0f,
    32.0f, 1.0f, 5.0f, 32.0f, 1.1f, 5.0f
};

GLfloat roadSegment8[] = {
    32.0f, 1.0f, 5.0f, 32.0f, 1.1f, 5.0f,
    34.0f, 1.0f, 7.0f, 34.0f, 1.1f, 7.0f,
    24.0f, 1.0f, 8.0f, 24.0f, 1.1f, 8.0f,
    21.0f, 1.0f, 6.0f, 21.0f, 1.1f, 6.0f
};

GLfloat roadSegment9[] = {
    21.0f, 1.0f, 6.0f, 21.0f, 1.1f, 6.0f,
    24.0f, 1.0f, 8.0f, 24.0f, 1.1f, 8.0f,
    12.0f, 1.0f, 4.0f, 12.0f, 1.1f, 4.0f,
    10.0f, 1.0f, 2.0f, 10.0f, 1.1f, 2.0f
};

GLfloat roadSegment10[] = {
    10.0f, 1.0f, 2.0f, 10.0f, 1.1f, 2.0f,
    12.0f, 1.0f, 4.0f, 12.0f, 1.1f, 4.0f,
    -25.0f, 1.0f, 2.0f, -25.0f, 1.1f, 2.0f,
    -25.0f, 1.0f, 0.0f, -25.0f, 1.1f, 0.0f
};

GLfloat roadSegment11[] = { //check
    -25.0f, 1.0f, 0.0f, -25.0f, 1.1f, 0.0f,
    -25.0f, 1.0f, 2.0f, -25.0f, 1.1f, 2.0f,
    -37.0f, 1.0f, -11.0f, -37.0f, 1.1f, -11.0f,
    -35.0f, 1.0f, -13.0f, -35.0f, 1.1f, -13.0f
};

GLfloat roadSegment12[] = {
    -35.0f, 1.0f, -13.0f, -35.0f, 1.1f, -13.0f,
    -37.0f, 1.0f, -11.0f, -37.0f, 1.1f, -11.0f,
    -45.0f, 1.0f, -40.0f, -45.0f, 1.1f, -40.0f,
    -42.0f, 1.0f, -42.0f, -42.0f, 1.1f, -42.0f
};

GLfloat roadSegment13[] = {
    -42.0f, 1.0f, -42.0f, -42.0f, 1.1f, -42.0f,
    -45.0f, 1.0f, -40.0f, -45.0f, 1.1f, -40.0f,
    -30.0f, 1.0f, -27.0f, -30.0f, 1.1f, -27.0f,
    -30.0f, 1.0f, -25.0f, -30.0f, 1.1f, -25.0f
};