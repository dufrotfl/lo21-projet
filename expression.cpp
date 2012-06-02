#include "expression.h"
#include "logSystem.h"
#include "constanteFactory.h"
#include "operateur.h"
#include "nombre.h"
#include "qdebug.h"

Expression::Expression() {
    _liste = new QVector<Constante*>();
}

Expression::Expression(const QString &str) {
    QString strcop = str.mid(1,str.size()-2);
    QStringList constantes(strcop.split(' '));
    QStringList::iterator i;
    _liste = new QVector<Constante*>();
    for(i=constantes.begin(); i != constantes.end(); i++) {
        try{
            Constante * p = ConstanteFactory::getConstante(*i);
            _liste->push_back(p);
        }
        catch(LogMessage e) {
            LogSystem::getInstance()->addMessage(e);
        }
    }
}

Nombre* Expression::eval() const {
    return new Entier();
}

QString Expression::toString() const {
    QString str;
    for(int i =0; i < _liste->size(); i++)
        str += _liste->at(i)->toString()+" ";
    return str;
}

Expression* Expression::operator+(Constante* c) {
    Expression* e = new Expression();
    if(typeid(*c)==typeid(Expression)) {
        Expression* cCopy = dynamic_cast<Expression*>(c);
        while(!getListe()->isEmpty()) {
            e->getListe()->push_back(getListe()->first());
            getListe()->pop_front();
        }
        while(!cCopy->getListe()->isEmpty()) {
            e->getListe()->push_back(cCopy->getListe()->first());
            cCopy->getListe()->pop_front();
        }
        e->getListe()->push_back(new Operateur("+",2));
    }
    if(typeid(*c)==typeid(Entier) || typeid(*c)==typeid(Rationnel) || typeid(*c)==typeid(Reel) || typeid(*c)==typeid(NombreComplexe)) {
        qDebug() << "nombre";
        while(!getListe()->isEmpty()) {
            e->getListe()->push_back(getListe()->first());
            getListe()->pop_front();
        }
        qDebug() << "nombre";
        e->getListe()->push_back(c);
        e->getListe()->push_back(new Operateur("+",2));
    }
    return e;
}

Expression* Expression::operator-(Constante* c) {
    Expression* e;
    if(typeid(*c)==typeid(Expression)) {
        Expression* cCopy = dynamic_cast<Expression*>(c);
        for(int i = 0; i < getListe()->size(); i++)
            e->getListe()->push_back(getListe()->at(i));
        for(int i = 0; i < cCopy->getListe()->size(); i++)
            e->getListe()->push_back(cCopy->getListe()->at(i));
        e->getListe()->push_back(new Operateur("-",2));
    }
    else if(typeid(*c)==typeid(Nombre)) {
        for(int i = 0; i < getListe()->size(); i++)
            e->getListe()->push_back(getListe()->at(i));
        e->getListe()->push_back(c);
        e->getListe()->push_back(new Operateur("-",2));
    }
    return e;
}

Expression* Expression::operator*(Constante* c) {
    Expression* e;
    if(typeid(*c)==typeid(Expression)) {
        Expression* cCopy = dynamic_cast<Expression*>(c);
        for(int i = 0; i < getListe()->size(); i++)
            e->getListe()->push_back(getListe()->at(i));
        for(int i = 0; i < cCopy->getListe()->size(); i++)
            e->getListe()->push_back(cCopy->getListe()->at(i));
        e->getListe()->push_back(new Operateur("*",2));
    }
    else if(typeid(*c)==typeid(Nombre)) {
        for(int i = 0; i < getListe()->size(); i++)
            e->getListe()->push_back(getListe()->at(i));
        e->getListe()->push_back(c);
        e->getListe()->push_back(new Operateur("*",2));
    }
    return e;
}

Expression* Expression::operator/(Constante* c) {
    Expression* e;
    if(typeid(*c)==typeid(Expression)) {
        Expression* cCopy = dynamic_cast<Expression*>(c);
        for(int i = 0; i < getListe()->size(); i++)
            e->getListe()->push_back(getListe()->at(i));
        for(int i = 0; i < cCopy->getListe()->size(); i++)
            e->getListe()->push_back(cCopy->getListe()->at(i));
        e->getListe()->push_back(new Operateur("/",2));
    }
    else if(typeid(*c)==typeid(Nombre)) {
        for(int i = 0; i < getListe()->size(); i++)
            e->getListe()->push_back(getListe()->at(i));
        e->getListe()->push_back(c);
        e->getListe()->push_back(new Operateur("/",2));
    }
    return e;
}
