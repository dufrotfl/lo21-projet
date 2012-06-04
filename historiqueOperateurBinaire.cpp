#include "historiqueOperateurBinaire.h"
#include "mainwindow.h"

void HistoriqueOperateurBinaire::undo() {
    _constante1=MainWindow::getPile()->pop();
    _constante2=MainWindow::getPile()->pop();
}

void HistoriqueOperateurBinaire::redo() {
    MainWindow::getPile()->push(_constante1);
    MainWindow::getPile()->push(_constante2);
}
