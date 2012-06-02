#include "pile.h"
#include "mainwindow.h"

Pile::Pile() {
    _pileStockage = new QStack<Constante*>();
    _pileAffichage = new QStack<Constante*>();
    _nbElemAffichable = 10;
    _tailleMax = 50;
}

Pile::~Pile() {
    while(!_pileStockage->isEmpty())
        delete _pileStockage->pop();

    while(!_pileAffichage->isEmpty())
        delete _pileAffichage->pop();
    delete _pileStockage;
    delete _pileAffichage;
}

void Pile::clear() {
    _pileStockage->clear();
    _pileAffichage->clear();
}

void Pile::drop() {
    if(!_pileStockage->isEmpty()) {
        Constante *temp = _pileAffichage->pop();
        _pileStockage->push(temp);
    }
}

void Pile::dup() {
    if(!_pileAffichage->isEmpty())
        _pileAffichage->push_front(_pileAffichage->top());
    // On modifie pileStockage ou pas???
}

void Pile::mean(int x) {
    int j = x;

    for(; j>0; j--) {
        if(!_pileAffichage->isEmpty() && _pileAffichage->size() >= 2) {
            Constante* temp1 = _pileAffichage->pop();
            Constante* temp2 = _pileAffichage->pop();

            // Faire la moyenne et stocker dans _pileAffichage
            //...
            _pileStockage->push(temp1);
            _pileStockage->push(temp2);
        }
    }
}

void Pile::sum(int x) {
    int j = x;

    for(; j>0; j--) {
        if(!_pileAffichage->isEmpty() && _pileAffichage->size() >= 2) {
            Constante* temp1 = _pileAffichage->pop();
            Constante* temp2 = _pileAffichage->pop();

            // Faire la somme et stocker dans _pileAffichage
            //...
            _pileStockage->push(temp1);
            _pileStockage->push(temp2);
        }
    }
}

void Pile::swap(int x, int y) {

}

void Pile::redo() {

}

void Pile::undo() {

}


Constante* Pile::pop() {
    /*if(_pileStockage->size() == _tailleMax)
         _pileStockage->pop_front();*/
    Constante* temp = _pileAffichage->pop();
    //_pileStockage->push(temp);
    return temp;
}

void Pile::push(Constante* constante) {
   _pileAffichage->push(constante);
}

void Pile::affiche() {

    if(!_pileAffichage->isEmpty()) {
        Constante * tmp = _pileAffichage->pop();
        MainWindow::getInstance()->setStackDisplayTextEdit(tmp->toString());
        affiche();
        _pileAffichage->push(tmp);
    }
}
