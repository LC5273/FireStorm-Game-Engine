#version 330

layout(location = 0) in vec4 position;
layout(location = 2) in vec2 texture_coord;

uniform mat4 model = mat4(1.0);
uniform mat4 view = mat4(1.0);
uniform mat4 projection = mat4(1.0);

out vec2 tex_coord;

uniform mat4 camMatrix = mat4(1.0);

void main() {
    //gl_Position = camMatrix * projection * view * model * vec4(position, 1.0);
    gl_Position = camMatrix * projection * view * model * position;
    //gl_Position = vec4(position, 1.0);
    
    tex_coord = texture_coord;
}