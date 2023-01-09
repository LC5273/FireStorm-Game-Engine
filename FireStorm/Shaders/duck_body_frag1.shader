#version 330 core

layout(location = 0) out vec4 color;

in vec4 pos;
in vec4 colour;

void main() {
	color = colour;
};