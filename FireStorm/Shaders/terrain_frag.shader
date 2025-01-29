#version 330

in vec4 vertexColor;

out vec4 color;

//uniform vec3 camPos;

void main() {
    color = vertexColor;
}