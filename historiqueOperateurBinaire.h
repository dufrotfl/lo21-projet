#ifndef HISTORIQUEOPERATEURBINAIRE_H
#define HISTORIQUEOPERATEURBINAIRE_H

#include "historique.h"
#include "constante.h"

class HistoriqueOperateurBinaire : public Historique {
    Constante* _constante1;
    Constante* _constante2;

    HistoriqueOperateurBinaire(Constante* c1, Constante* c2):_constante1(c1), _constante2(c2) {}
    ~HistoriqueOperateurBinaire() {delete _constante1; delete _constante2;}

    void undo();
    void redo();
};

#endif
