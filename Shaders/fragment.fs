#version 330 core

out vec4 color;
in vec3 Dcolor;
in vec2 TexCoord;
//in vec3 Fcolor;

//vec4 Fcolor;

uniform sampler2D tex;

void main()
{
	//color = texture(tex, TexCoord);
	vec4 Fcolor = vec4(Dcolor.x, Dcolor.y, Dcolor.z, 0.0);
	//color = Fcolor*texture(tex, TexCoord);
	color = texture(tex, TexCoord);
}
