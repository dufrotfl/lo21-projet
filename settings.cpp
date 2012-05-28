#include "settings.h"

Settings * Settings::_instance = 0;

Settings::Settings() {
    _utilisationDeComplexe = NON_COMPLEXE;
    _angles = DEGRES;
    _typeConstante = ENTIER;
}

Settings::Settings(UtilisationDeComplexe comp, Angles an, TypeConstante cons) {
    _utilisationDeComplexe = comp;
    _angles = an;
    _typeConstante = cons;
}

Settings * Settings::getInstance() {
    if(!_instance)
        _instance = new Settings();
    return _instance;
}

void Settings::freeInstance() {
    if(!_instance)
        delete _instance;
}


