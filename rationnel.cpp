#include "rationnel.h"
#include "reel.h"
#include "entier.h"
#include "nombreComplexe.h"


NombreComplexe* Rationnel::toNombreComplexe() {
    return new NombreComplexe(this, new Rationnel(0, 1));
}

