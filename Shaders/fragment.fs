#version 330 core

out vec4 color;
in vec3 Dcolor;

uniform vec4 inColor;

void main()
{
	color = vec4(Dcolor, 1.0f);
}
