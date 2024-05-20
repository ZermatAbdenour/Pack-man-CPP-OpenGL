#version 400 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;
uniform mat4 u_model;
uniform mat4 u_projection;
out vec2 texCoord;
void main() {
    gl_Position = u_projection * u_model * vec4(aPos.x, aPos.y, 0.0, 1.0);
    texCoord = aTexCoord;
}