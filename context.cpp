#include "context.h"

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
    ofstream ofs("contextSettings.ros", ios::binary);

    Settings * set = Settings::getInstance();
    ofs.write((char *)&set, sizeof(set));
    Pile * p = MainWindow::getInstance()->getPile();
    p->push(new Entier(5));
    ofs.write((char *)&p, sizeof(p));
}

void Context::chargerContext() {
    ifstream ifs("context.ros", ios::binary);

    Pile * p = new Pile();

    ifs.read((char *)&p, sizeof(p));
    Settings * set = Settings::getInstance();
    ifs.read((char *)&set, sizeof(set));
}
