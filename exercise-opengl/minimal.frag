// Fragment Shader - file "minimal.frag"

// Taken from https://gist.github.com/dlivingstone/628320

// Modified by Alexander Wiebel

#version 130

in vec3 ex_Color;
out vec4 out_Color;

void main(void)
{
    out_Color = vec4(ex_Color,1.0);
}




