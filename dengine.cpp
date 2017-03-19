#include "dengine.h"
#include "ui_dengine.h"


DEngine::DEngine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DEngine)
{
    ui->setupUi(this);

    SDL_Init(SDL_INIT_EVERYTHING);

    _sdlWindow=SDL_CreateWindowFrom((void*)ui->openGLWidget->winId());


}

DEngine::~DEngine()
{
    delete ui;

}
