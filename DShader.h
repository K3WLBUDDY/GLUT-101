#ifndef DSHADERH
#define DSHADERH

#include <GL/glew.h>
#include <string>
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <fstream>


class DShader
{
private:
  GLuint _vs;
  GLuint _fs;
  GLuint _pID;
  

  DShader() : _vs(0), _fs(0), _pID(0) {}

public:

  void compileShader(std::string& filePath);
  void linkShader();
  void use();
  GLuint getProgramID();
  //void unuse();
};

#endif
