#version 460 core

layout (location = 0) in vec3 apos;

void main()
{
    vec4 vec = vec4(0, 0, 1, 1);
    gl_Position = vec;
}