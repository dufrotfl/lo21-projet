#include "nombreNonComplexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"

NombreNonComplexe* NombreNonComplexe::operator+(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER)
        return new Entier(toEntier()->getVal()+nb->toEntier()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL)
         return new Reel(toReel()->getVal()+nb->toReel()->getVal());
    else
         return new Rationnel(toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur()+nb->toRationnel()->getNumerateur()*toRationnel()->getDenominateur(), toRationnel()->getDenominateur()*nb->toRationnel()->getDenominateur());
}

NombreNonComplexe* NombreNonComplexe::operator-(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER)
         return new Entier(toEntier()->getVal()-nb->toEntier()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL)
        return new Reel(toReel()->getVal()-nb->toReel()->getVal());
    else
        return new Rationnel(toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur()-nb->toRationnel()->getNumerateur()*toRationnel()->getDenominateur(), toRationnel()->getDenominateur()*nb->toRationnel()->getDenominateur());
}

NombreNonComplexe* NombreNonComplexe::operator/(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER)
        return new Entier(toEntier()->getVal()/nb->toEntier()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL)
        return new Reel(toReel()->getVal()/nb->toReel()->getVal());
    else {
        return new Rationnel(toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur(), toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur());

    }
}

NombreNonComplexe* NombreNonComplexe::operator*(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER)
        return new Entier(toEntier()->getVal()*nb->toEntier()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL)
        return new Reel(toReel()->getVal()*nb->toReel()->getVal());
    else
        return new Rationnel(toRationnel()->getNumerateur()*nb->toRationnel()->getNumerateur(), toRationnel()->getDenominateur()*nb->toRationnel()->getDenominateur());
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
