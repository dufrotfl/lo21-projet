#include "pile.h"
#include "operateur.h"
#include "mainwindow.h"
#include "qdebug.h"

Pile::Pile() {
    _pileStockage = new QStack<Constante*>();
    _pileAffichage = new QStack<Constante*>();
    _nbElemAffichable = 10;
}

Pile::~Pile() {
    _pileAffichage->clear();
    _pileStockage->clear();
    delete _pileStockage;
    delete _pileAffichage;
}

void Pile::clear() {
    _pileStockage->clear();
    _pileAffichage->clear();
}

void Pile::drop() {
    if(!_pileAffichage->isEmpty()) {
        Constante *temp = _pileAffichage->pop();
        //_pileStockage->push(temp);
    }
}

void Pile::dup() {
    if(!_pileAffichage->isEmpty())
        _pileAffichage->push_back(_pileAffichage->top());
}

void Pile::mean(int x) {
    int j = x;
    int cpt = 0;
    for(; j>0; j--) {
        if(!_pileAffichage->isEmpty() && _pileAffichage->size() >= 2) {
            cpt++;
            Constante* temp1 = _pileAffichage->pop();
            Constante* temp2 = _pileAffichage->pop();

            Operateur* op = new Operateur("+", 2);
            _pileAffichage->push(op->call(temp1, temp2));
            delete op;
        }
    }
    if(cpt != 0) {
        Operateur* op = new Operateur("/",2);
        _pileAffichage->push(op->call(_pileAffichage->pop(), new Entier(cpt+1)));
        delete op;
    }

}

void Pile::sum(int x) {
    int j = x;
    for(; j>0; j--) {
        if(!_pileAffichage->isEmpty() && _pileAffichage->size() >= 2) {
            Constante* temp1 = _pileAffichage->pop();
            Constante* temp2 = _pileAffichage->pop();

            Operateur* op = new Operateur("+", 2);
            _pileAffichage->push(op->call(temp1, temp2));
        }
    }
}

void Pile::swap(int x, int y) {
    Constante* tmp = _pileAffichage->at(y);
    _pileAffichage->replace(y, _pileAffichage->at(x));
    _pileAffichage->replace(x, tmp);

}

void Pile::redo() {

}

void Pile::undo() {

}

Constante* Pile::sommet() {
    if(!_pileAffichage->isEmpty())
        return _pileAffichage->top();
    else
        throw LogMessage("La pile est vide, impossible de récupérer le sommet.", 1);
}


Constante* Pile::pop() {
    /*if(_pileStockage->size() == _tailleMax)
         _pileStockage->pop_front();*/
    Constante* temp;
    if(!_pileAffichage->isEmpty())
        temp = _pileAffichage->pop();
    else
        throw LogMessage("Pas assez d'élément à dépiler.", 1);
    //_pileStockage->push(temp);
    return temp;
}

void Pile::push(Constante* constante) {
    if(constante)
        _pileAffichage->push(constante);
}

void Pile::affiche() {
    int i = 0;
    while(i < _nbElemAffichable && !_pileAffichage->isEmpty()) {
            Constante * tmp = _pileAffichage->pop();
            _pileStockage->push(tmp);
            MainWindow::getInstance()->setStackDisplayTextEdit(tmp->toString());
            i++;
    }
    while(i > 0 && !_pileStockage->isEmpty()) {
        _pileAffichage->push(_pileStockage->pop());
        i--;
    }
}
