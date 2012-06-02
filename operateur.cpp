#include "operateur.h"

#include "entier.h"

Constante* Operateur::call(Constante* c1, Constante *c2) const{
    if(_operateur=="+") {
        if(typeid(*c1)==typeid(NombreComplexe) && typeid(*c2)==typeid(NombreComplexe)) {
            c1 = dynamic_cast<NombreComplexe*>(c1);

            //return *c1+c2;
        }
    }
    return new Entier(0);
}
