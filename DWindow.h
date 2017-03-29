#ifndef DWINDOWH
#define DWINDOWH

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "DShader.h"

enum class state{PLAY, STOP};

class DWindow
{
private:

  SDL_Window* _window;
  SDL_GLContext _glContext;
  //GLfloat _vertices[8];
  GLuint _VBO;
  GLuint _VAO;
  DShader ds;
  //int width = 1024;
  //int height = 500;

  void init();
  void processInput();
  void draw();
  void shaderCompile();

public:

  void run();

  state s;
};

#endif
