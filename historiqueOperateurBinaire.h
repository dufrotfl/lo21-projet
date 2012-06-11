#ifndef HISTORIQUEOPERATEURBINAIRE_H
#define HISTORIQUEOPERATEURBINAIRE_H

#include "historique.h"
#include "constante.h"

class HistoriqueOperateurBinaire : public Historique {
    Constante* _constante1;
    Constante* _constante2;
    Constante* _resultat;
public:
    HistoriqueOperateurBinaire(Constante* c1, Constante* c2):_constante1(c1->clone()), _constante2(c2->clone()) {}
    ~HistoriqueOperateurBinaire() {delete _constante1; delete _constante2;}

    Constante* setResultat(Constante* res) {_resultat=res->clone(); return _resultat;}
    void undo();
    void redo();
};

#endif
