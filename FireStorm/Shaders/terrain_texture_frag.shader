#version 330

layout(location = 0) out vec4 color;

in vec4 vertexColor;

//out vec4 color;

uniform sampler2D terrain_texture;

in vec2 tex_coord;

void main() {
    //color = vertexColor;
    
    vec4 texture_colour = texture(terrain_texture, tex_coord);
    color = texture_colour;
}