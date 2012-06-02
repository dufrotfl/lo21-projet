#include <QtGui/QApplication>
#include "logSystem.h"
#include "context.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow * w = MainWindow::getInstance();
    w->show();
    //Context::getInstance()->sauvegardeContext();
    //Context::getInstance()->chargerContext();S
   // delete w;
    return a.exec();
}
