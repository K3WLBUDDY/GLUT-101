#include "DTex.h"

bool DTex::loadTexture(std::string _texPath)
{
	const char* cTexPath = _texPath.c_str();
	
	_image = SOIL_load_image(cTexPath, &_width, &_height, 0 ,SOIL_LOAD_RGB);

	if(_image!=NULL)
		return true;
	else
		return false;
}

void DTex::genTexture()
{
	//GLuint Tex;
	glGenTextures(1, &tex);

	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, _image);
	glGenerateMipmap(GL_TEXTURE_2D);

	SOIL_free_image_data(_image);
	glBindTexture(GL_TEXTURE_2D, 0);



	//return Tex;
}