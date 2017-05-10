#include "DWindow.h"
#include "glm/gtx/string_cast.hpp"
GLfloat _vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

glm::vec3 cubePositions[] = {
  glm::vec3( 0.0f,  0.0f,  0.0f), 
  glm::vec3( 2.0f,  5.0f, -15.0f), 
  glm::vec3(-1.5f, -2.2f, -2.5f),  
  glm::vec3(-3.8f, -2.0f, -12.3f),  
  glm::vec3( 2.4f, -0.4f, -3.5f),  
  glm::vec3(-1.7f,  3.0f, -7.5f),  
  glm::vec3( 1.3f, -2.0f, -2.5f),  
  glm::vec3( 1.5f,  2.0f, -2.5f), 
  glm::vec3( 1.5f,  0.2f, -1.5f), 
  glm::vec3(-1.3f,  1.0f, -1.5f)  
};

bool keys[1024];


glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);//Sets the position of the Camera in the World
glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f); //The Coordinates of the target i.e the object to be focused by the camera
glm::vec3 cameraDirection = glm::normalize(cameraPosition - cameraTarget);//The Direction Vector from the Camera Position to the Target
glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);//A Unit Vector that points in the +Y Direction in the world space
glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));//Right Vector of the Camera
glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);//Up Vector of the Camera
glm::vec3 cameraFront = glm::vec3 (0.0f, 0.0f, -1.0f);
//glm::vec3 front;

GLfloat cameraSpeed = 0.05f;
GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;
GLfloat lastX = 800*0.5;
GLfloat lastY = 600*0.5;
GLfloat xPos, yPos, yaw=0.0f, pitch=0.0f, xOffset=0, yOffset=0,sens;

bool firstMouse = true;

void DWindow::run() //Should run at 60 FPS
{
  init(); //Initializes SDL and GLEW

  glViewport(0,0,800,600); //Specifies Coordinates for NDC to Window Transformation
  //0,0 refer to the coordinates of the lower left corner

  _df.setRefreshRate(); //Gets Default Refresh Rate of the Monitor
  
  shaderCompile(); //Compiles VS and FS
  texInit();

  //Generates Buffer Object names. Names can be reused
  //only if deleted via glDeleteBuffers. Number specifies the No. of buffers needed
  glGenBuffers(1, &_VBO);
  

  //Generates Vertex Array Object Names.
  glGenVertexArrays(1, &_VAO);

  //Binds the specified Name
  glBindVertexArray(_VAO);

  // GL_ARRAY_BUFFER specifies Vertex Attributes
  glBindBuffer(GL_ARRAY_BUFFER, _VBO);
 

  //Specifies the Data being stored in the Buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);


  //Takes the Currently bound Buffer Data and sends it to the Shader
  //Shader Attribute is specified by the location
  //The attributes created afer generating a VAO are pointed to by that particular VAO
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)0); //Position
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));//Color
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));//TexCoord


  //Enables the Attribute at specified Location
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);

  //Unbinds the VBO
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  
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

  GLfloat currentFrame = SDL_GetTicks()*0.001;
  deltaTime = currentFrame - lastFrame;
  lastFrame = currentFrame;

  cameraSpeed = 5.0f*deltaTime;
  SDL_Event evnt;

  while(SDL_PollEvent(&evnt))
  {
    switch(evnt.type)
    {
      case SDL_QUIT:
        s= state::STOP;
        break;

      case SDL_KEYDOWN:

        keys[evnt.key.keysym.sym]=true;

        std::cout<<"\n KEY IN INT : "<<evnt.key.keysym.sym;

        if(keys[SDLK_w])
          cameraPosition += cameraSpeed * cameraFront;
        if(keys[SDLK_s])
          cameraPosition -= cameraSpeed * cameraFront;
        if(keys[SDLK_a])
          cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)*cameraSpeed);
        if(keys[SDLK_d])
          cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)*cameraSpeed);
        break;

      case SDL_KEYUP:

        keys[evnt.key.keysym.sym]=false;
        break;

      case SDL_MOUSEMOTION:

      //while()

        xPos = evnt.motion.xrel;
        yPos = evnt.motion.yrel;

        std::cout<<"\n CURSOR COORDINATES : "<<xPos<<"...."<<yPos;


        sens = 0.05f;

        yaw += xPos*sens;
        pitch += yPos*sens;

        if(pitch>89.0f)
          pitch=89.0f;
        if(pitch<-89.0f)
          pitch=-89.0f;

        glm::vec3 front;
        front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        front.y = sin(glm::radians(pitch));
        front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
        cameraFront = glm::normalize(front);
        break;
    }
  }
}

void DWindow::draw()
{
  
  glClearDepth(1.0);
  glClearColor(0.3f, 0.3f, 0.7f, 1.0f);
  glEnable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glm::mat4 trans; //Transformation Matrix
  glm::mat4 model; //Model Matrix
  //glm::mat4 view;  //View Matrix
  glm::mat4 projection; //Perspective Projection matrix
  float width = 1024, height = 768;

  GLfloat ticks = SDL_GetTicks()*0.001;//FFS Use Floating Points! Also convert Milliseconds to Seconds
  GLfloat radius = 10.0f;
  GLfloat camX = sin(SDL_GetTicks()*0.001) * radius;
  GLfloat camZ = cos(SDL_GetTicks()*0.001) * radius;
  glm::mat4 view;
   projection = glm::perspective(glm::radians(50.0f), width/height, 0.1f, 100.0f);

  
  view = glm::lookAt(cameraPosition, cameraPosition+cameraFront, cameraUp);
 
  std::cout<<"\n CAMERA POSITION COORDINATES : "<<glm::to_string(cameraPosition)<<std::endl;
  std::cout<<"\n CAMERA FRONT COORDINATES : "<<glm::to_string(cameraFront);
  ds.use();

  GLint inColorLocation = glGetUniformLocation(ds.getProgramID(), "inColor");
  //GLint transformLocation = glGetUniformLocation(ds.getProgramID(), "transform");
  GLint modelLocation = glGetUniformLocation(ds.getProgramID(), "model");
  GLint viewLocation = glGetUniformLocation(ds.getProgramID(), "view");
  GLint projectionLocation  =glGetUniformLocation(ds.getProgramID(), "projection");
 
  
  //trans = glm::rotate(trans, ticks*glm::radians((1.0f)), glm::vec3(0.0, 0.0, 1.0));

  
  //glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(trans));
  //glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
  glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
  glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

  glBindTexture(GL_TEXTURE_2D, _dt.tex);

  glBindVertexArray(_VAO);
  for(GLuint i = 0; i < 10; i++)
  {
    glm::mat4 model;
    model = glm::translate(model, cubePositions[i]);
    GLfloat angle = glm::radians(20.0f) * i; 
    model = glm::rotate(model, ticks*angle, glm::vec3(1.0f, 0.3f, 0.5f));
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);
  }

  
  glBindVertexArray(0);
  
  

  SDL_GL_SwapWindow(_window);

 

}


void DWindow::init()
{

  SDL_Init(SDL_INIT_EVERYTHING);


  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);//Min OpenGL 3 Core

  _window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800 ,600, SDL_WINDOW_OPENGL);


  if(_window==nullptr)
    std::cout<<"\n Failed to Create SDL Window";

  _glContext = SDL_GL_CreateContext(_window);

  if(_glContext==nullptr)
    std::cout<<"\n Failed to Create OpenGL Context";

  _error = glewInit();

  if(_error!=GLEW_OK)
    std::cout<<"\n Failed to Initialize GLEW";

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_SetRelativeMouseMode(SDL_TRUE);

}

void DWindow::shaderCompile()
{

    std::string fp = "Shaders/vertex.vs"; //Locations of VS and FS
    std::string vp = "Shaders/fragment.fs";

    ds.compileShader(fp);
    ds.compileShader(vp);
    ds.linkShader();
}

void DWindow::texInit()
{
  success =_dt.loadTexture("textures/container.jpg");//TODO - Add Texture File
  if(success == false)
    std::cout<<"\n Failed to Load Texture";
  else
    _dt.genTexture();

}
