#include "dengine.h"
#include <QApplication>
#include <QWindow>
#include <thread>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DEngine w;

    w.show();

    return a.exec();
}


