#include "nombreComplexe.h"

NombreComplexe::~NombreComplexe() {
    delete _reel;
    delete _img;
}

void NombreComplexe::sign() {
    Nombre * temp = dynamic_cast<Nombre*>(&((*_reel)*(*_reel) + (*_img)*(*_img)));
    _reel /= temp;
    temp->sign();
    _img /= temp;
}

void NombreComplexe::sqr() {

}

void NombreComplexe::cube() {


}
