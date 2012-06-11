#include "rationnel.h"
#include "reel.h"
#include "entier.h"
#include "nombreComplexe.h"


NombreComplexe* Rationnel::toNombreComplexe() {
    return new NombreComplexe(this, new Rationnel(0, 1));
}

Rationnel* Rationnel::clone() const {
    return new Rationnel(getNumerateur(), getDenominateur());
}

int Rationnel::pgcd(int a, int b) const {
    if(a==0 || b==0)
            return 0;
    if(a<0)
        a=-a;
    if(b<0)
        b=-b;

    while(a!=b) {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }

    return a;
}

void Rationnel::simplifier() {
    if(_numerateur == 0) {
        _denominateur=1;
        return;
    }
    int i = pgcd(_denominateur, _numerateur);

    _numerateur/=i;
    _denominateur/=i;
    if(_denominateur<0) {
        _denominateur=-_denominateur;
        _numerateur=-_numerateur;
    }
}

void Rationnel::pow(Entier *e) {
    for(int i=0; i<e->getVal()-1; i++)
        sqr();
}
