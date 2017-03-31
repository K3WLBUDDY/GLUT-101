#include "dengine.h"
#include "ui_dengine.h"


DEngine::DEngine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DEngine)
{
    ui->setupUi(this);

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
        qCritical("Could not Initialize SDL : %s ", SDL_GetError());

    //ui->openGLWidget->initializeGL();

    _sdlWindow = SDL_CreateWindowFrom((void*)ui->openGLWidget->winId());

    Uint32 flags = SDL_GetWindowFlags(_sdlWindow);
    qCritical("Window Flags : %d", flags);


    if(_sdlWindow==NULL)
        qCritical("Could not Create SDL Window : %s ", SDL_GetError());

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    //SDL_GL_SetAttribute(SDL_WINDOW_OPENGL, 1);

    _glContext = SDL_GL_CreateContext(_sdlWindow);

    if(_glContext==nullptr)
        qCritical("Could not Create OpenGL Context : %s ", SDL_GetError());
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);



    draw();

}

void DEngine::draw()
{
    glClearDepth(1.0);
    glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


DEngine::~DEngine()
{
    delete ui;

}
