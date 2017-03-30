#include "dengine.h"
#include "ui_dengine.h"


DEngine::DEngine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DEngine)
{
    ui->setupUi(this);

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
        qCritical("Could not Initialize SDL : %s ", SDL_GetError());

    _sdlWindow = SDL_CreateWindowFrom((void*)ui->openGLWidget->winId());

    if(_sdlWindow==NULL)
        qCritical("Could not Create SDL Window : %s ", SDL_GetError());

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    //SDL_GL_SetAttribute(SDL_WINDOW_OPENGL, 1);

    _glContext = SDL_GL_CreateContext(_sdlWindow);

    if(_glContext==nullptr)
        qCritical("Could not Create OpenGL Context : %s ", SDL_GetError());

}


DEngine::~DEngine()
{
    delete ui;

}
