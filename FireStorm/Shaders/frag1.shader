#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 colour = vec4(0.8f, 0.5f, 1.0f, 1.0f);
uniform vec2 light_pos = vec2(1.0f);
uniform vec2 mouse_pos = vec2(1.0f);

in vec4 pos;

void main() {
	float intensity = 1.0f / length(pos.xy - light_pos) * 0.1;
	color = colour * intensity;
};