#ifndef DTEXH
#define DTEXH

#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <string>

class DTex
{
private:

	int _width, _height;

	unsigned char* _image;

	std::string _texPath;

	
	
public:

	bool loadTexture(std::string _texPath);
	void genTexture();
	GLuint tex;
};

#endif