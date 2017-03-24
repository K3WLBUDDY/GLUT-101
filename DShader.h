#ifndef DSHADERH
#define DSHADERH

#include <GL/glew.h>
#include <string>

class DShader
{
private:
  GLuint _vs;
  GLuint _fs;
  GLuint _pID;

  bool compileShader(const string& filePath);
  bool linkShader();
  void use();
  void unuse();
};
