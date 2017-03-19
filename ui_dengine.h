/********************************************************************************
** Form generated from reading UI file 'dengine.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DENGINE_H
#define UI_DENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DEngine
{
public:
    QWidget *centralWidget;
    QOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DEngine)
    {
        if (DEngine->objectName().isEmpty())
            DEngine->setObjectName(QStringLiteral("DEngine"));
        DEngine->resize(1920, 1080);
        centralWidget = new QWidget(DEngine);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(560, 0, 851, 421));
        DEngine->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DEngine);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 25));
        DEngine->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DEngine);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DEngine->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DEngine);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DEngine->setStatusBar(statusBar);

        retranslateUi(DEngine);

        QMetaObject::connectSlotsByName(DEngine);
    } // setupUi

    void retranslateUi(QMainWindow *DEngine)
    {
        DEngine->setWindowTitle(QApplication::translate("DEngine", "DEngine", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DEngine: public Ui_DEngine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DENGINE_H
