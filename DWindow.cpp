#include "DWindow.h"
GLfloat _vertices[] = {
  -0.5f,  -0.5f, 0.0f,  // Top Right
  0.5f, -0.5f, 0.0f,  // Bottom Right
  0.0f, 0.5f, 0.0f,  // Bottom Left
};

GLfloat _indices[] = {
  0, 1, 3, 
  1, 2, 3
};

void DWindow::run() //Should run at 60 FPS
{
  init(); //Initializes SDL and GLEW
  _df.setRefreshRate();
  shaderCompile(); //Compiles VS and FS

  //Generates Buffer Object names. Names can be reused
  //only if deleted via glDeleteBuffers


  glGenBuffers(1, &_VBO);
  glGenBuffers(1, &_EBO);

  //Generates Vertex Array Object Names.
  glGenVertexArrays(1, &_VAO);

  //Binds the specified Name
  glBindVertexArray(_VAO);

  // GL_ARRAY_BUFFER specifies Vertex Attributes
  glBindBuffer(GL_ARRAY_BUFFER, _VBO);
 

  //Specifies the Data being stored in the Buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);

   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices), _indices, GL_STATIC_DRAW);

  //Takes the Currently bound Buffer Data and sends it to the Shader
  //Shader Attribute is specified by the location
  //The attributes created afer generating a VAO are pointed to by that particular VAO
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (GLvoid*)0);

  //Enables the Attribute at specified Location
  glEnableVertexAttribArray(0);

  //Unbinds the VBO
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  //Unbinds the VAO
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
  //Binds the Vertex Array Object
  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
  ds.use();

  GLuint pID = ds.getProgramID();
  GLint inColorLocation = glGetUniformLocation(pID, "inColor");
  //SDL_Delay(50);
  GLuint ticks = SDL_GetTicks() * 0.01;

  GLfloat colorValue = sin(ticks)/2+0.5;
  glUniform4f(inColorLocation, 0.0f, colorValue, 0.0f, 1.0f);
  glBindVertexArray(_VAO);

  //Draws from the specified Index
  glDrawArrays(GL_TRIANGLES, 0, 3);

  //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  

  SDL_GL_SwapWindow(_window);

 

}


void DWindow::init()
{

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);//Min OpenGL 3 Core

  _window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024 ,768, SDL_WINDOW_OPENGL);


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

void DWindow::shaderCompile()
{

    std::string fp = "Shaders/vertex.vs"; //Locations of VS and FS
    std::string vp = "Shaders/fragment.fs";

    ds.compileShader(fp);
    ds.compileShader(vp);
    ds.linkShader();
}
