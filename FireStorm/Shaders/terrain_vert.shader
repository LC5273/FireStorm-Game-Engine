#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

uniform mat4 model = mat4(1.0);
uniform mat4 view = mat4(1.0);
uniform mat4 projection = mat4(1.0);
out vec4 vertexColor;

uniform mat4 camMatrix = mat4(1.0);

void main() {
    gl_Position = camMatrix * projection * view * model * vec4(position, 1.0);
    vertexColor = color;
}