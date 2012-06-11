#ifndef HISTORIQUEOPERATEURPUSH_H
#define HISTORIQUEOPERATEURPUSH_H


#include "historique.h"
#include "constante.h"

class HistoriqueOperateurPush : public Historique {
    Constante* _constante1;
public:
    HistoriqueOperateurPush(Constante* c1):_constante1(c1->clone()) {}
    ~HistoriqueOperateurPush() {delete _constante1;}
    void undo();
    void redo();
};


#endif // HISTORIQUEOPERATEURPUSH_H
