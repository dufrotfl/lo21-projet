#include <QtGui/QApplication>
#include "logSystem.h"
#include "context.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow * w = MainWindow::getInstance();
    try {
        Context::getInstance()->chargerContext();
    }
    catch(LogMessage lm) {
        LogSystem::getInstance()->addMessage(lm);
    }
    w->show();
    w->freeInstance();
    return a.exec();
}
