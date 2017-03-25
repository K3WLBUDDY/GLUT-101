#include "DWindow.h"
#


void DWindow::init()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  _window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024 ,768, SDL_WINDOW_OPENGL);
  GLfloat _vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
  };

  if(_window==nullptr)
    std::cout<<"\n Failed to Create SDL Window";

  _glContext = SDL_GL_CreateContext(_window);

  if(_glContext==nullptr)
    std::cout<<"\n Failed to Create OpenGL Context";

  GLenum error = glewInit();

  if(error!=GLEW_OK)
    std::cout<<"\n Failed to Initialize GLEW";

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void DWindow::run() //Should run at 60 FPS
{
  init();

  while(s!= state::STOP)
  {
    processInput();
    draw();
  }

  glDeleteVertexArrays(1, &_VAO);
  glDeleteBuffers(1, &_VBO);
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

void DWindow::draw()
{
  glClearDepth(1.0);

  glGenBuffers(1, &_VBO);
  glGenVertexArrays(1, &_VAO);

  glBindVertexArray(_VAO);
  glBindBuffer(GL_ARRAY_BUFFER, _VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  ds.compileShader("Shaders/vertex.vs");
  ds.compileShader("Shaders/fragment.fs");
  ds.linkShader();
  ds.use();


  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  SDL_GL_SwapWindow(_window);//Swapping for Double Buffer
}
