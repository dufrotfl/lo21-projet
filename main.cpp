#include <QtGui/QApplication>
#include "logSystem.h"
#include "context.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Context::getInstance()->chargerContext();
    MainWindow * w = MainWindow::getInstance();
    w->show();
    //Context::getInstance()->sauvegardeContext();
    return a.exec();
}
