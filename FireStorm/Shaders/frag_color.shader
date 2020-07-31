#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 colour1 = vec4(0.0f, 0.0f, 1.0f, 1.0f);
uniform vec2 light_pos = vec2(1.0f);
uniform vec2 mouse_pos = vec2(1.0f);

in vec4 pos;
in vec4 colour;

void main() {
	float intensity = 1.0f / length(pos.xy - light_pos) * 0.1;
	color = colour * intensity;
};