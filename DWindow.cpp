#include "DWindow.h"

void DWindow::init()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  _window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366 ,768, SDL_WINDOW_OPENGL);

  if(_window==nullptr)
    std::cout<<"\n Failed to Create SDL Window";


}

void DWindow::run()
{
  init();

  while(s!= state::STOP)
  {
    processInput();
  }
}

void DWindow::processInput()
{
  SDL_Event evnt;

  while(SDL_PollEvent(&evnt))
  {
    switch(evnt.type)
    {
      case SDL_QUIT:
        s= state::STOP;
        break;

    }
  }
}
