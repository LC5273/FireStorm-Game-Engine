#version 330 core

layout(location = 0) out vec4 color;

uniform sampler2D enemy_texture;

in vec2 tex_coord;

void main() {
	vec4 texture_colour = texture(enemy_texture, tex_coord);
	color = texture_colour;
};