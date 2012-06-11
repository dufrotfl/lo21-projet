#include "historiqueOperateurUnaire.h"
#include "mainwindow.h"

void HistoriqueOperateurUnaire::undo() {
    MainWindow::getInstance()->getPile()->pop();
    MainWindow::getInstance()->getPile()->push(_constante1);
}

void HistoriqueOperateurUnaire::redo() {
    MainWindow::getInstance()->getPile()->pop();
    MainWindow::getInstance()->getPile()->push(_resultat);
}
