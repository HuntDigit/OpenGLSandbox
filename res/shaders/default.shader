#shader vertex
#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec2 texCoords;

out vec2 v_texCoords;

uniform mat4 u_Model;
uniform mat4 u_Camera;

void main(){
    v_texCoords = texCoords;
    gl_Position =  u_Camera * u_Model * position;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;
in vec2 v_texCoords;

uniform vec4 u_Color;
uniform sampler2D u_Texture[8];
uniform int u_nTexture;

void main(){

    vec4 texColor = texture(u_Texture[0], v_texCoords);

    if (u_nTexture == 1) {
        texColor = texture(u_Texture[1], v_texCoords);
    }
    if (u_nTexture == 2) {
        texColor = texture(u_Texture[2], v_texCoords);
    }
    if (u_nTexture == 3) {
        texColor = texture(u_Texture[3], v_texCoords);
    }
    if (u_nTexture == 4) {
        texColor = texture(u_Texture[4], v_texCoords);
    }
    if (u_nTexture == 5) {
        texColor = texture(u_Texture[5], v_texCoords);
    }

    color = texColor * u_Color;
}