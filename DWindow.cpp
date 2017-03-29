#include "DWindow.h"
GLfloat _vertices[] = {
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f,
  0.0f, 0.5f, 0.0f
};


void DWindow::init()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  _window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024 ,768, SDL_WINDOW_OPENGL);


  if(_window==nullptr)
    std::cout<<"\n Failed to Create SDL Window";

  _glContext = SDL_GL_CreateContext(_window);

  if(_glContext==nullptr)
    std::cout<<"\n Failed to Create OpenGL Context";

  GLenum error = glewInit();

  if(error!=GLEW_OK)
    std::cout<<"\n Failed to Initialize GLEW";

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

}

void DWindow::run() //Should run at 60 FPS
{
  init();
  shaderCompile();

  glGenBuffers(1, &_VBO);
  glGenVertexArrays(1, &_VAO);

  glBindVertexArray(_VAO);
  glBindBuffer(GL_ARRAY_BUFFER, _VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

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
  glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  ds.use();

  glBindVertexArray(_VAO);

  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(0);

  SDL_GL_SwapWindow(_window);

}

void DWindow::shaderCompile()
{

    std::string fp = "Shaders/vertex.vs";
    std::string vp = "Shaders/fragment.fs";

    ds.compileShader(fp);
    ds.compileShader(vp);
    ds.linkShader();
}
