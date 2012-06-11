#include "pile.h"
#include "operateur.h"
#include "mainwindow.h"
#include "qdebug.h"
#include "historiqueOperateurBinaire.h"
#include "historiqueOperateurSumMean.h"
#include "historiqueOperateurPush.h"

Pile::Pile() {
    _pileStockage = new QStack<Constante*>();
    _pileAffichage = new QStack<Constante*>();
    _pileUndo = new QStack<Historique*>();
    _pileRedo = new QStack<Historique*>();
    _nbElemAffichable = 10;
}

Pile::~Pile() {
    _pileAffichage->clear();
    _pileStockage->clear();
    _pileUndo->clear();
    _pileRedo->clear();
    delete _pileRedo;
    delete _pileUndo;
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
    }
}

void Pile::dup() {
    if(!_pileAffichage->isEmpty()) {
        Constante * e= _pileAffichage->top()->clone();
        _pileAffichage->push_back(e);
        HistoriqueOperateurPush *h = new HistoriqueOperateurPush(e);
        MainWindow::getInstance()->getPile()->ajouteHistorique(h);
    }
}

void Pile::mean(int x) {
    int j = x;
    QStack<Constante*>* _tab = new QStack<Constante*>();
    if(x!=0 && !_pileAffichage->isEmpty())
        _tab->push_front(_pileAffichage->top());
    int cpt = 0;
    for(; j>0; j--) {
        if(!_pileAffichage->isEmpty() && _pileAffichage->size() >= 2) {
            cpt++;
            Constante* temp1 = _pileAffichage->pop();
            Constante* temp2 = _pileAffichage->pop();            
            _tab->push_front(temp2);
            Operateur* op = new Operateur("+", 2);
            _pileAffichage->push(op->call(temp1, temp2));
            delete op;
            // nécéssité de retirer autant d'élément dans pile undo que d'appel à l'opérateur + sinon on va avoir dans l'historique chaque opération afin d'obtenir la moyenne
            _pileUndo->pop();
        }
    }
    if(cpt != 0) {
        Operateur* op = new Operateur("/",2);
        _pileAffichage->push(op->call(_pileAffichage->pop(), new Entier(cpt+1)));
        delete op;
        _pileUndo->pop();
    }
    HistoriqueOperateurSumMean *h = new HistoriqueOperateurSumMean(_tab);
    MainWindow::getInstance()->getPile()->ajouteHistorique(h);
    h->setResultat(_pileAffichage->top());
}

void Pile::sum(int x) {
    int j = x;
    QStack<Constante*>* _tab = new QStack<Constante*>();
    if(x!=0 && !_pileAffichage->isEmpty())
        _tab->push_front(_pileAffichage->top());
    for(; j>0; j--) {
        if(!_pileAffichage->isEmpty() && _pileAffichage->size() >= 2) {
            Constante* temp1 = _pileAffichage->pop();
            Constante* temp2 = _pileAffichage->pop();
            _tab->push_front(temp2);
            Operateur* op = new Operateur("+", 2);
            _pileAffichage->push(op->call(temp1, temp2));
            delete op;
            // nécéssité de retirer autant d'élément dans pile undo que d'appel à l'opérateur + sinon on va avoir dans l'historique chaque opération afin d'obtenir la somme
            _pileUndo->pop();
        }
    }
    HistoriqueOperateurSumMean *h = new HistoriqueOperateurSumMean(_tab);
    MainWindow::getInstance()->getPile()->ajouteHistorique(h);
    h->setResultat(_pileAffichage->top());
}

void Pile::swap(int x, int y) {
    if(x < _pileAffichage->size() && y < _pileAffichage->size()) {
        Constante* tmp = _pileAffichage->at(y);
        _pileAffichage->replace(y, _pileAffichage->at(x));
        _pileAffichage->replace(x, tmp);
    }
    else
        throw LogMessage("Swap impossible, veuillez vérifier les deux indices ! ", 1);
}

void Pile::redo() {
    if(_pileRedo->size()>=1) {
        Historique* h = _pileRedo->pop();
        h->redo();
        _pileUndo->push(h);
    }
    else
        throw LogMessage("Historique vide, impossible de rétablir.", 2);
}

void Pile::undo() {
    if(_pileUndo->size()>=1) {
        Historique* h = _pileUndo->pop();
        h->undo();
        _pileRedo->push(h);
    }
    else
        throw LogMessage("Historique vide, impossible d'annuler.", 2);
}

Constante* Pile::sommet() {
    if(!_pileAffichage->isEmpty())
        return _pileAffichage->top();
    else
        throw LogMessage("La pile est vide, impossible de récupérer le sommet.", 1);
}


Constante* Pile::pop() {
    Constante* temp;
    if(!_pileAffichage->isEmpty())
        temp = _pileAffichage->pop();
    else
        throw LogMessage("Pas assez d'élément à dépiler.", 1);
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

QString Pile::getPileString() const {
    QString str;
    int i = 0;
    while(i < _nbElemAffichable && !_pileAffichage->isEmpty()) {
        Constante * tmp = _pileAffichage->pop();
        _pileStockage->push(tmp);
        str = tmp->toString()+" "+str;
        i++;
    }
    while(i > 0 && !_pileStockage->isEmpty()) {
        _pileAffichage->push(_pileStockage->pop());
        i--;
    }
    return str;
}
