#ifndef HISTORIQUEOPERATEURSWAP_H
#define HISTORIQUEOPERATEURSWAP_H

#include "historique.h"
#include "entier.h"

class HistoriqueOperateurSwap : public Historique {
    Entier* _entier1;
    Entier* _entier2;
public:
    HistoriqueOperateurSwap(Entier* c1, Entier* c2):_entier1(c1->clone()), _entier2(c2->clone()) {}
    ~HistoriqueOperateurSwap() {delete _entier1; delete _entier2;}

    void undo();
    void redo();
};


#endif // HISTORIQUEOPERATEURSWAP_H
