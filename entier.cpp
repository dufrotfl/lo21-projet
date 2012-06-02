#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "nombreComplexe.h"

NombreComplexe* Entier::toNombreComplexe() {
    return new NombreComplexe(this, new Entier(0));
}

