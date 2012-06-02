#include "reel.h"
#include "rationnel.h"
#include "entier.h"
#include "nombreComplexe.h"


NombreComplexe* Reel::toNombreComplexe() {
    return new NombreComplexe(this, new Reel(1));
}
