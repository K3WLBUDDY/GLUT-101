#-------------------------------------------------
#
# Project created by QtCreator 2017-02-05T00:28:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DEngine
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        dengine.cpp

HEADERS  += dengine.h\
            /usr/include/SDL2/SDL.h

FORMS    += dengine.ui

LIBS     += -L/usr/lib -lSDL2

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lSDL2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lSDL2
else:unix: LIBS += -L$$PWD/../../../../usr/lib/ -lSDL2

INCLUDEPATH += $$PWD/../../../../usr/include/SDL2
DEPENDPATH += $$PWD/../../../../usr/include/SDL2
