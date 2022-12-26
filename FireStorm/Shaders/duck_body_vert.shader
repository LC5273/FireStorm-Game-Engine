#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

out vec4 pos;
out vec4 colour;

void main() {
	pos = position;
	colour = color;
}