#ifndef HISTORIQUEOPERATEURUNAIRE_H
#define HISTORIQUEOPERATEURUNAIRE_H

#include "historique.h"
#include "constante.h"

class HistoriqueOperateurUnaire : public Historique {
    Constante* _constante1;
    Constante* _resultat;
public:
    HistoriqueOperateurUnaire(Constante* c1):_constante1(c1->clone()) {}
    ~HistoriqueOperateurUnaire() {delete _constante1;}

    Constante* setResultat(Constante* res) {_resultat=res->clone(); return _resultat;}
    void undo();
    void redo();
};

#endif
