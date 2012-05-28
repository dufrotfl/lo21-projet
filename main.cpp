#include <QtGui/QApplication>
#include "Gui.h"
#include "logSystem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Gui* g = Gui::getInstance();
    g->exec();
    LogSystem::getInstance()->addMessage(LogMessage("Lol", 1));
    return a.exec();
}
