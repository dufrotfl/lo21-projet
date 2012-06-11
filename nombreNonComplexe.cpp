#include "nombreNonComplexe.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include "logSystem.h"
#include "qdebug.h"

NombreNonComplexe* NombreNonComplexe::operator+(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER)
        return new Entier(toEntier()->getVal()+nb->toEntier()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL)
         return new Reel(toReel()->getVal()+nb->toReel()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::RATIONNEL) {
        Rationnel* tmpRationnel = new Rationnel(toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur()+nb->toRationnel()->getNumerateur()*toRationnel()->getDenominateur(), toRationnel()->getDenominateur()*nb->toRationnel()->getDenominateur());
        tmpRationnel->simplifier();
        return tmpRationnel;
    }
}

NombreNonComplexe* NombreNonComplexe::operator-(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER)
         return new Entier(toEntier()->getVal()-nb->toEntier()->getVal());
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL)
        return new Reel(toReel()->getVal()-nb->toReel()->getVal());
    else {
        Rationnel* tmpRationnel = new Rationnel(toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur()-nb->toRationnel()->getNumerateur()*toRationnel()->getDenominateur(), toRationnel()->getDenominateur()*nb->toRationnel()->getDenominateur());
        tmpRationnel->simplifier();
        return tmpRationnel;
    }
}

NombreNonComplexe* NombreNonComplexe::operator/(NombreNonComplexe* nb) {
    if(Settings::getInstance()->getTypeConstante()==Settings::ENTIER) {
        if(nb->toEntier()->getVal()==0)
            throw LogMessage("Division par 0 non autorisée.", 1);
        qDebug() << nb->toEntier()->getVal();
        return new Entier(toEntier()->getVal()/nb->toEntier()->getVal());
    }
    else if(Settings::getInstance()->getTypeConstante()==Settings::REEL) {
        if(nb->toReel()->getVal()==0)
            throw LogMessage("Division par 0 non autorisée.", 1);
        return new Reel(toReel()->getVal()/nb->toReel()->getVal());
    }
    else {
        if(toRationnel()->getDenominateur()*nb->toRationnel()->getNumerateur()==0)
            throw LogMessage("Division par 0 non autorisée.", 1);
        Rationnel* tmpRationnel = new Rationnel(toRationnel()->getNumerateur()*nb->toRationnel()->getDenominateur(), toRationnel()->getDenominateur()*nb->toRationnel()->getNumerateur());
        tmpRationnel->simplifier();
        return tmpRationnel;
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
    }
    else if(typeid(*this)==typeid(Reel)) {
        Reel* tmpReel = dynamic_cast<Reel*>(this);
        return new Entier(tmpReel->getVal());
    }
    else
        throw LogMessage("Problème de conversion en entier.", 1);
}

Rationnel* NombreNonComplexe::toRationnel() {
    if(typeid(*this)==typeid(Rationnel))
        return dynamic_cast<Rationnel*>(this);
    else if(typeid(*this)==typeid(Entier)) {
        Entier* tmpEntier = dynamic_cast<Entier*>(this);
        return new Rationnel(tmpEntier->getVal(), 1);
    }
    else if(typeid(*this)==typeid(Reel)) {
        Reel* tmpReel = dynamic_cast<Reel*>(this);
        return new Rationnel(tmpReel->getVal(), 1);
    }
    else
        throw LogMessage("Problème de conversion en rationnel.", 1);
}

Reel* NombreNonComplexe::toReel() {
    if(typeid(*this)==typeid(Reel))
        return dynamic_cast<Reel*>(this);
    else if(typeid(*this)==typeid(Entier)) {
        Entier* tmpEntier = dynamic_cast<Entier*>(this);
        return new Reel(tmpEntier->getVal());
    }
    else if(typeid(*this)==typeid(Rationnel)) {
        Rationnel* tmpRationnel = dynamic_cast<Rationnel*>(this);
        return new Reel(tmpRationnel->getFloatVal());
    }
    else
        throw LogMessage("Problème de conversion en réel.", 1);
}
