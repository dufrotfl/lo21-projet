#include "historiqueOperateurPush.h"
#include "mainwindow.h"

void HistoriqueOperateurPush::undo() {
    MainWindow::getInstance()->getPile()->pop();
}

void HistoriqueOperateurPush::redo() {
    MainWindow::getInstance()->getPile()->push(_constante1);
}

