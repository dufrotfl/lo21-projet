#ifndef PILE_H
#define PILE_H
#include "constante.h"
#include "QStack.h"
#include "entier.h"
#include "logMessage.h"

class Pile {
private:
    QStack<Constante*> * _pileStockage;
    QStack<Constante*> * _pileAffichage;
    int _nbElemAffichable;
public:
    Pile();
    ~Pile();
    void push(Constante* constante);
    Constante* pop() throw (LogMessage);
    Constante* sommet();
    int getPileAffichageSize() const {return _pileAffichage->size();}
    void setNbElemAffichable(int i) {_nbElemAffichable=i;}
    void drop();
    void clear();
    void dup();
    void swap(int,int);
    void sum(int);
    void mean(int);
    void redo();
    void undo();
    void affiche();
};

#endif PILE_H
