#version 330 core

layout(location = 0) in vec4 position;
//layout(location = 1) in vec4 color;
layout(location = 2) in vec2 texture_coord;

out vec4 pos;
//out vec4 colour;
out vec2 tex_coord;

void main() {
	gl_Position = position;
	
	pos = position;
	//colour = color;
	tex_coord = texture_coord;
}