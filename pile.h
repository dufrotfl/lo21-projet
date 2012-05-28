#ifndef PILE_H
#define PILE_H
#include "constante.h"
#include "QStack.h"
#include "context.h"

class Pile {
private:
    QStack<Constante*> * _pileStockage;
    QStack<Constante*> * _pileAffichage;
    int _nbElemAffichable;
    int _tailleMax;
public:
    Pile();
    ~Pile();
    void push(Constante* constante);
    Constante* pop();
    void drop();
    void clear();
    void dup();
    void swap(int,int);
    void sum(int);
    void mean(int);
    void redo();
    void undo();
    void chargerDepuisContexte(const Context &);
};

#endif PILE_H
