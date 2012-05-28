#include "gui.h"


Gui* Gui::_instance = 0;

Gui::Gui() {
    _pile = new Pile();
    _mainwindow = new MainWindow();
}

Gui::~Gui() {
    delete _pile;
    delete _mainwindow;
}

Gui* Gui::getInstance() {
    if(!_instance)
        _instance = new Gui();
    return _instance;
}

void Gui::freeInstance() {
    if(!_instance)
        delete _instance;
}

Pile* Gui::getPile() {
    return _pile;
}

MainWindow* Gui::getMainWindow() {
    return _mainwindow;
}

void Gui::exec() {
    // Chargement des contexts dans les piles etc
    _mainwindow->show();
}


void Gui::eval() {
    QString input(_mainwindow->getInput());
    if(input=="") {
        Constante* c = _pile->pop();
        if(typeid(c)==typeid(Expression)) {
            Expression* e = dynamic_cast<Expression*>(c);
            try {
                _pile->push(e->eval());
            }
            catch(ConstanteException a) {
                LogSystem::getInstance()->addMessage(LogMessage("lol", 1));
            }
        }
        else
            _pile->push(c);
    }
    else if(_mainwindow->getInput().indexOf(QRegExp("^'.+'$"))!=-1)
        _pile->push(ConstanteFactory::getConstante(_mainwindow->getInput()));
    else {

    }
}
