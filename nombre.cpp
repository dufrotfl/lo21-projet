#include "nombre.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include "nombreComplexe.h"
#include "expression.h"

Expression* Nombre::operator+(Expression* e) {
    return *e+this;
}

Expression* Nombre::operator-(Expression* e) {
    return *e-this;
}

Expression* Nombre::operator/(Expression* e) {
    return *e/this;
}

Expression* Nombre::operator*(Expression* e) {
    return *e*this;
}

Constante* Nombre::Asin() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = dynamic_cast<Constante*>(this);
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Sin impossible sur un nombre complexe", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;
    valeur = sin(nc->getFloatVal());

    // Conversion en degrés dans le cas ou les degrés sont sélectionnés
    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        valeur /= 180 / PI;

    if(Settings::getInstance()->getTypeConstante() == Settings::ENTIER)
        return new Entier(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::REEL)
        return new Reel(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL)
        return new Rationnel(valeur, 1);
}

Constante* Nombre::Acos() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = this;
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Cos impossible sur un nombre complexe.", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;
    valeur = cos(nc->getFloatVal());

    // Conversion en degrés dans le cas ou les degrés sont sélectionnés
    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        valeur /= 180 / PI;
    // On converti pour avoir un type de retour correspondant au paramètre de la calculatrice
    if(Settings::getInstance()->getTypeConstante() == Settings::ENTIER)
        return new Entier(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::REEL)
        return new Reel(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL)
        return new Rationnel(valeur, 1);
}

Constante* Nombre::Atan() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = this;
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Tan impossible sur un nombre complexe.", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;
    valeur = tan(nc->getFloatVal());

    // Conversion en degrés dans le cas ou les degrés sont sélectionnés
    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        valeur /= 180 / PI;
    // On converti pour avoir un type de retour correspondant au paramètre de la calculatrice
    if(Settings::getInstance()->getTypeConstante() == Settings::ENTIER)
        return new Entier(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::REEL)
        return new Reel(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL)
        return new Rationnel(valeur, 1);
}

Constante* Nombre::Asinh() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = this;
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Sinh impossible sur un nombre complexe.", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;
    valeur = sinh(nc->getFloatVal());
    // On converti pour avoir un type de retour correspondant au paramètre de la calculatrice
    if(Settings::getInstance()->getTypeConstante() == Settings::ENTIER)
        return new Entier(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::REEL)
        return new Reel(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL)
        return new Rationnel(valeur, 1);
}

Constante* Nombre::Acosh() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = this;
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Cosh impossible sur un nombre complexe.", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;
    valeur = cosh(nc->getFloatVal());
    // On converti pour avoir un type de retour correspondant au paramètre de la calculatrice
    if(Settings::getInstance()->getTypeConstante() == Settings::ENTIER)
        return new Entier(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::REEL)
        return new Reel(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL)
        return new Rationnel(valeur, 1);
}

Constante* Nombre::Atanh() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = this;
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Tanh impossible sur un nombre complexe.", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;
    valeur = tanh(nc->getFloatVal());
    // On converti pour avoir un type de retour correspondant au paramètre de la calculatrice
    if(Settings::getInstance()->getTypeConstante() == Settings::ENTIER)
        return new Entier(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::REEL)
        return new Reel(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL)
        return new Rationnel(valeur, 1);
}

Constante* Nombre::Aln() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = this;
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Ln impossible sur un nombre complexe.", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;
    valeur = log(nc->getFloatVal());
    // On converti pour avoir un type de retour correspondant au paramètre de la calculatrice
    if(Settings::getInstance()->getTypeConstante() == Settings::ENTIER)
        return new Entier(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::REEL)
        return new Reel(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL)
        return new Rationnel(valeur, 1);
}

Constante* Nombre::Alog() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = this;
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Log impossible sur un nombre complexe.", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;
    valeur = log10(nc->getFloatVal());

    // On converti pour avoir un type de retour correspondant au paramètre de la calculatrice
    if(Settings::getInstance()->getTypeConstante() == Settings::ENTIER)
        return new Entier(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::REEL)
        return new Reel(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL)
        return new Rationnel(valeur, 1);
}

Constante* Nombre::Ainv() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = this;
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Inv impossible sur un nombre complexe.", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;

    // On converti pour avoir un type de retour correspondant au paramètre de la calculatrice
    if(Settings::getInstance()->getTypeConstante() == Settings::ENTIER) {
        valeur = 1/(nc->getFloatVal());
        return new Entier(valeur);
    }
    else if(Settings::getInstance()->getTypeConstante() == Settings::REEL) {
        valeur = 1/(nc->getFloatVal());
        return new Reel(valeur);
    }
    else if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL) {
        return new Rationnel(1, nc->getFloatVal());
    }
}

Constante* Nombre::Asqrt() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = this;
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Sqrt impossible sur un nombre complexe.", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;
    valeur = sqrt(nc->getFloatVal());

    // On converti pour avoir un type de retour correspondant au paramètre de la calculatrice
    if(Settings::getInstance()->getTypeConstante() == Settings::ENTIER)
        return new Entier(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::REEL)
        return new Reel(valeur);
    else if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL)
        return new Rationnel(valeur, 1);
}

