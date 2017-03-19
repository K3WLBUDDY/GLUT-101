#ifndef DWINDOWH
#define DWINDOWH

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>


enum class state{PLAY, STOP};

class DWindow
{
private:

  SDL_Window* _window;

  void init();
  void processInput();
  void drawGame();

public:

  void run();

  state s;
};

#endif
