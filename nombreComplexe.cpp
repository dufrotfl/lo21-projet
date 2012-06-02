#include "nombreComplexe.h"
#include "entier.h"

NombreComplexe::~NombreComplexe() {
    delete _reel;
    delete _img;
}

void NombreComplexe::sign() {
    _reel->sign();
    _img->sign();
}

void NombreComplexe::sqr() {
    Entier *e = new Entier(2);
    delete _reel;
    _reel->sqr();
    _reel = *_reel+(*(*e*_reel)*_img);
    _img->sqr();
    _reel = *_reel-_img;
    delete _img;
    _img = new Entier(0);
}

void NombreComplexe::cube() {
    //nc->sqr();
}

QString NombreComplexe::toString() const { 
    return QString(getReel().toString()+"$"+getImg().toString());
}
