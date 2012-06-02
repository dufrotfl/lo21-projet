#include "nombreNonComplexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"

NombreNonComplexe* NombreNonComplexe::operator+(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER)
        return new Entier(this->toEntier()->getVal()+nb->toEntier()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL)
         return new Reel(this->toReel()->getVal()+nb->toReel()->getVal());
    else
         return new Rationnel(this->toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur()+nb->toRationnel()->getNumerateur()*this->toRationnel()->getDenominateur(), this->toRationnel()->getDenominateur()*nb->toRationnel()->getDenominateur());
}

NombreNonComplexe* NombreNonComplexe::operator-(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER)
         return new Entier(this->toEntier()->getVal()*nb->toEntier()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL)
        return new Reel(this->toReel()->getVal()*nb->toReel()->getVal());
    else
        return new Rationnel(this->toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur()-nb->toRationnel()->getNumerateur()*this->toRationnel()->getDenominateur(), this->toRationnel()->getDenominateur()*nb->toRationnel()->getDenominateur());
}

NombreNonComplexe* NombreNonComplexe::operator/(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER)
        return new Entier(this->toEntier()->getVal()/nb->toEntier()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL)
        return new Reel(this->toReel()->getVal()/nb->toReel()->getVal());
    else {
        return new Rationnel(this->toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur(), this->toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur());

    }
}

NombreNonComplexe* NombreNonComplexe::operator*(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER)
        return new Entier(this->toEntier()->getVal()*nb->toEntier()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL)
        return new Reel(this->toReel()->getVal()*nb->toReel()->getVal());
    else
        return new Rationnel(this->toRationnel()->getNumerateur()*nb->toRationnel()->getNumerateur(), this->toRationnel()->getDenominateur()*nb->toRationnel()->getDenominateur());
}

Entier* NombreNonComplexe::toEntier() {
    if(typeid(*this)==typeid(Entier))
        return dynamic_cast<Entier*>(this);
    else if(typeid(*this)==typeid(Rationnel)) {
        Rationnel* tmpRationnel = dynamic_cast<Rationnel*>(this);
        return new Entier(tmpRationnel->getNumerateur()/tmpRationnel->getDenominateur());
        delete tmpRationnel;
    }
    else if(typeid(*this)==typeid(Reel)) {
        Reel* tmpReel = dynamic_cast<Reel*>(this);
        return new Entier(tmpReel->getVal());
        delete tmpReel;
    }
    else
        throw LogMessage("Problème de conversion en entier.", 1);
}

Rationnel* NombreNonComplexe::toRationnel() {
    if(typeid(*this)==typeid(Rationnel))
        return dynamic_cast<Rationnel*>(this);
    else if(typeid(*this)==typeid(Entier)) {
        Entier* tmpEntier = dynamic_cast<Entier*>(this);
        return new Rationnel();
        delete tmpEntier;
    }
    else if(typeid(*this)==typeid(Reel)) {
        Reel* tmpReel = dynamic_cast<Reel*>(this);
        return new Rationnel();
        delete tmpReel;
    }
    else
        throw LogMessage("Problème de conversion en rationnel.", 1);
}

Reel* NombreNonComplexe::toReel() {
    if(typeid(*this)==typeid(Reel))
        return dynamic_cast<Reel*>(this);
    else if(typeid(*this)==typeid(Entier)) {
        Entier* tmpEntier = dynamic_cast<Entier*>(this);
        return new Reel();
        delete tmpEntier;
    }
    else if(typeid(*this)==typeid(Rationnel)) {
        Rationnel* tmpRationnel = dynamic_cast<Rationnel*>(this);
        return new Reel();
        delete tmpRationnel;
    }
    else
        throw LogMessage("Problème de conversion en réel.", 1);
}

Reel* NombreNonComplexe::Asin() const{
    Reel* r;
    /*_val = sin(_val);
    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        _val *= 180 / PI;*/
    return r;
}

Reel* NombreNonComplexe::Acos() const{
    Reel* r;
   /* _val = cos(_val);
    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        _val *= 180 / PI;*/
    return r;
}

Reel* NombreNonComplexe::Atan() const{
    Reel* r;
   /* _val = tan(_val);
    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        _val *= 180 / PI;*/
    return r;
}

Reel* NombreNonComplexe::Asinh() const{
    Reel* r;
   /* _val = sinh(_val);
    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        _val *= 180 / PI;*/
    return r;
}

Reel* NombreNonComplexe::Acosh() const{
    Reel* r;
   /* _val = cosh(_val);
    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        _val *= 180 / PI;*/
    return r;
}

Reel* NombreNonComplexe::Atanh() const{
    Reel* r;
   /* _val = tanh(_val);
    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        _val *= 180 / PI;*/
    return r;
}

Reel* NombreNonComplexe::Aln() const{
    Reel* r;
    //_val = log(_val);
    return r;
}

Reel* NombreNonComplexe::Alog() const{
   Reel* r;
   // _val = log10(_val);
    return r;
}

Reel* NombreNonComplexe::Ainv() const{
    Reel* r;
    //_val = 1/_val;
    return r;
}

Reel* NombreNonComplexe::Asqrt() const{
    Reel* r;
    // = sqrt(_val);
    return r;
}

