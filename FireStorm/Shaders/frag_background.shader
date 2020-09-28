#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 colour1 = vec4(1.0f, 0.0f, 1.0f, 1.0f);

uniform sampler2D texture1;

in vec4 pos;
in vec2 tex_coord;

void main() {
	vec4 texture_colour = texture(texture1, tex_coord);
	color = texture_colour;
};