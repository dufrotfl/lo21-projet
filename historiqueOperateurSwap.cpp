#include "historiqueOperateurSwap.h"
#include "mainwindow.h"

void HistoriqueOperateurSwap::undo() {
    MainWindow::getInstance()->getPile()->swap(_entier1->getVal(), _entier2->getVal());
}

void HistoriqueOperateurSwap::redo() {
    MainWindow::getInstance()->getPile()->swap(_entier1->getVal(), _entier2->getVal());
}
