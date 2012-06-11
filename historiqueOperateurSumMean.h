#ifndef HISTORIQUEOPERATEURSUMMEAN_H
#define HISTORIQUEOPERATEURSUMMEAN_H

#include "historique.h"
#include "constante.h"
#include "qstack.h"

class HistoriqueOperateurSumMean : public Historique {
    QStack<Constante*>* _tabConstante;
    Constante* _resultat;
public:
    HistoriqueOperateurSumMean(QStack<Constante*>* c1);
    ~HistoriqueOperateurSumMean() {delete _tabConstante;}

    Constante* setResultat(Constante* res) {_resultat=res->clone(); return _resultat;}
    void undo();
    void redo();
};

#endif // HISTORIQUEOPERATEURSUMMEAN_H
