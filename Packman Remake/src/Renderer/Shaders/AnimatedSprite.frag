#version 400 core

in vec2 texCoord;

out vec4 fragColor;

uniform sampler2D u_texture;
uniform float u_spriteColumns;
uniform float u_spriteRows;
uniform uint u_spriteIndex;

void main() {
    vec2 pos = vec2(u_spriteIndex % int(u_spriteColumns), int(u_spriteIndex / u_spriteColumns));
    fragColor = texture(u_texture, vec2((texCoord.x / u_spriteColumns) + pos.x * (1.0 / u_spriteColumns), (texCoord.y / u_spriteRows) + pos.y * (1.0 / u_spriteRows)));
}