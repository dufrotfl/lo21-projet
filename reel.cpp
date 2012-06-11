#include "reel.h"
#include "rationnel.h"
#include "entier.h"
#include "nombreComplexe.h"

NombreComplexe* Reel::toNombreComplexe() {
    return new NombreComplexe(this, new Reel(1));
}

Reel* Reel::clone() const {
    return new Reel(getVal());
}

void Reel::pow(Entier *e) {
    for(int i=0; i<e->getVal()-1; i++)
        sqr();
}
