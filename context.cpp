#include "context.h"
#include "qsettings.h"


Context* Context::_instance = 0;

Context::Context() {

}

Context* Context::getInstance() {
    if(!_instance)
        _instance = new Context();
    return _instance;
}

void Context::freeInstance() {
    if(!_instance)
        delete _instance;
}

void Context::sauvegardeContext() {
    /*Settings set = *Settings::getInstance();
    Pile p = *MainWindow::getInstance()->getPile();

    QSettings fichier_contexte("contexte.ini", QSettings::IniFormat);
    //fichier_contexte.setValue("Settings", qVariantFromValue(set));
    fichier_contexte.setValue("Pile", qVariantFromValue(p));
    fichier_contexte.sync();*/
}

void Context::chargerContext() {
    //Settings set = *Settings::getInstance();
    //QSettings fichier_contexte("contexte.ini", QSettings::IniFormat);
    //set.setAngles(fichier_contexte.value("Settings", qVariantFromValue(set)).value<Settings>());
    //fichier_contexte.sync();

    //MainWindow::getInstance()->setPile(&fichier_contexte.value("Pile", qVariantFromValue(Pile())).value<Pile>());
    //fichier_contexte.sync();
}
