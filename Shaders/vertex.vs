#version 330 core

//Use glVertexAttribPointer to point the Shader Variables
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 Dcolor;
out vec2 TexCoord;


uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position = projection*view*model*vec4(position, 1.0f);
	Dcolor = color;
	TexCoord = vec2(texCoord.x, 1.0-texCoord.y);
}
