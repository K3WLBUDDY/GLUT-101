#version 330 core

out vec4 color;
in vec3 Dcolor;
in vec2 TexCoord;


uniform sampler2D tex;

void main()
{
	
	vec4 Fcolor = vec4(Dcolor.x, Dcolor.y, Dcolor.z, 0.0);
	
	color = texture(tex, TexCoord);
}
