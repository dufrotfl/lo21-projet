#include "nombreComplexe.h"

NombreComplexe::~NombreComplexe() {
    delete _reel;
    delete _img;
}

void NombreComplexe::sign() {
    //a = a/ (a*a+b*b)
    //b = b/ (a*a+b*b)
    /*NombreNonComplexe * temp = dynamic_cast<NombreNonComplexe*>((*_reel)*(*_reel)+(*_img)*(_img));
    _reel /= temp;
    temp->sign();
    _img /= temp;*/
}

void NombreComplexe::sqr() {

}

void NombreComplexe::cube() {

}

QString NombreComplexe::toString() const { 
    return QString(getReel().toString()+"$"+getImg().toString());
}
