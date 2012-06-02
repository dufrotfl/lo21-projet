#include "nombre.h"
#include "reel.h"
#include "nombreComplexe.h"

Reel* Nombre::Asin() {
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

    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        valeur *= 180 / PI;
    return new Reel(valeur);
}

Reel* Nombre::Acos() {
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

    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        valeur *= 180 / PI;
    return new Reel(valeur);
}

Reel* Nombre::Atan() {
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

    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        valeur *= 180 / PI;
    return new Reel(valeur);
}

Reel* Nombre::Asinh() {
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

    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        valeur *= 180 / PI;
    return new Reel(valeur);
}

Reel* Nombre::Acosh() {
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

    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        valeur *= 180 / PI;
    return new Reel(valeur);
}

Reel* Nombre::Atanh() {
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

    if(Settings::getInstance()->getAngles() == Settings::DEGRES)
        valeur *= 180 / PI;
    return new Reel(valeur);
}

Reel* Nombre::Aln() {
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
    return new Reel(valeur);
}

Reel* Nombre::Alog() {
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
    return new Reel(valeur);
}

Reel* Nombre::Ainv() {
    // on test si c'est un complexe
    // si oui throw logmessage
    // sinon on cast en nombreNonComplexe et on effectue l'opération
    Constante* c = this;
    if(typeid(*c)==typeid(NombreComplexe)) {
        throw LogMessage("Inv impossible sur un nombre complexe.", 1);
    }
    NombreNonComplexe * nc = dynamic_cast<NombreNonComplexe*>(c);
    float valeur = 0.0;
    valeur = 1/(nc->getFloatVal());
    return new Reel(valeur);
}

Reel* Nombre::Asqrt() {
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
    return new Reel(valeur);
}

