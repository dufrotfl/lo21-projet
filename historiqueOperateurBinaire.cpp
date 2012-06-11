#include "historiqueOperateurBinaire.h"
#include "mainwindow.h"

void HistoriqueOperateurBinaire::undo() {
    MainWindow::getInstance()->getPile()->pop();
    MainWindow::getInstance()->getPile()->push(_constante1);
    MainWindow::getInstance()->getPile()->push(_constante2);
}

void HistoriqueOperateurBinaire::redo() {
    MainWindow::getInstance()->getPile()->pop();
    MainWindow::getInstance()->getPile()->pop();
    MainWindow::getInstance()->getPile()->push(_resultat);
}
