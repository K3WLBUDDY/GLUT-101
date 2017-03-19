#ifndef DWINDOWH
#define DWINDOWH

#include <iostream>
#include <SDL2/SDL.h>

enum class state{PLAY, STOP};

class DWindow
{
private:

  SDL_Window* _window;
  void init();
  void processInput();

public:

  void run();

  state s;
};

#endif
