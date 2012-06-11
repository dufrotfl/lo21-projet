#include "nombreComplexe.h"
#include "entier.h"

NombreComplexe* NombreComplexe::clone() const {
    NombreNonComplexe * c1 = dynamic_cast<NombreNonComplexe*>(getReel()->clone());
    NombreNonComplexe * c2 = dynamic_cast<NombreNonComplexe*>(getImg()->clone());
    return new NombreComplexe(c1, c2);
}

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
    _reel->sqr();
    _reel = *_reel+(*(*e*_reel)*_img);
    _img->sqr();
    _reel = *_reel-_img;
    _img = new Entier(0);
}

void NombreComplexe::cube() {
    NombreComplexe* clone = this->clone();
    delete _img;
    delete _reel;
    clone = *(*clone* clone)* clone;
    this->_reel = clone->_reel;
    this->_img = clone->_img;
}

QString NombreComplexe::toString() const { 
    return QString(getReel()->toString()+"$"+getImg()->toString());
}

NombreComplexe* NombreComplexe::operator+(NombreComplexe* nc) {
    return new NombreComplexe(*_reel+nc->getReel(), *_img+nc->getImg());
}

NombreComplexe* NombreComplexe::operator-(NombreComplexe* nc) {
    return new NombreComplexe(*_reel-nc->getReel(), *_img-nc->getImg());
}

NombreComplexe* NombreComplexe::operator/(NombreComplexe* nc) {
    NombreNonComplexe* aCarre=nc->getReel();
    aCarre->sqr();
    NombreNonComplexe* bCarre=nc->getImg();
    bCarre->sqr();

    NombreComplexe* res = new NombreComplexe(*(*(*_reel * nc->getReel()) + *_img*nc->getImg()) / (*aCarre+bCarre), *(*(*_reel * nc->getImg()) - *nc->getReel()*_img) / (*aCarre+bCarre));
    return res;
}

NombreComplexe* NombreComplexe::operator*(NombreComplexe* nc) {
    return new NombreComplexe(*(*_reel*nc->getReel())-*_img*nc->getImg(), *(*_reel*nc->getImg())+*nc->getReel()*_img);
}
