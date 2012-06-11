#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "nombreComplexe.h"

NombreComplexe* Entier::toNombreComplexe() {
    return new NombreComplexe(this, new Entier(0));
}

Entier* Entier::clone() const {
    return new Entier(getVal());
}

void Entier::pow(Entier *e) {
    for(int i=0; i<e->getVal()-1; i++)
        sqr();
}
