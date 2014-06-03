// Vertex Shader - file "minimal.vert"

// Taken from https://gist.github.com/dlivingstone/628320

// Modified by Alexander Wiebel

#version 130

in vec3 in_Position;
in vec3 in_Color;
out vec3 ex_Color;

void main(void)
{
    ex_Color = in_Color;
    gl_Position = vec4(in_Position, 1.0);
}



