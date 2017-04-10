#ifndef DWINDOWH
#define DWINDOWH

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "DShader.h"
#include "DFps.h"
#include "DTex.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum class state{PLAY, STOP};

class DWindow
{
private:

  SDL_Window* _window;
  SDL_GLContext _glContext;
  GLuint _VBO;
  GLuint _VAO;
  GLuint _EBO;
  GLenum _error;
  DShader ds;
  DFps _df;
  DTex _dt;
  bool success;

  void init();
  void processInput();
  void draw();
  void shaderCompile();
  void texInit();

 

public:

  void run();

  state s;
};

#endif
