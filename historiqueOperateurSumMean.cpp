#include "historiqueOperateurSumMean.h"
#include "mainwindow.h"

HistoriqueOperateurSumMean::HistoriqueOperateurSumMean(QStack<Constante *> *c1) {
    _tabConstante = c1;
}

void HistoriqueOperateurSumMean::undo() {
    MainWindow::getInstance()->getPile()->pop();
    for(int i=0; i < _tabConstante->size(); i++) {
        MainWindow::getInstance()->getPile()->push(_tabConstante->at(i));
    }
}

void HistoriqueOperateurSumMean::redo() {
    for(int i=0; i < _tabConstante->size(); i++) {
        MainWindow::getInstance()->getPile()->pop();
    }
    MainWindow::getInstance()->getPile()->push(_resultat);
}
