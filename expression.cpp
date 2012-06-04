#include "expression.h"
#include "mainwindow.h"

Expression::Expression() {
}

Expression::Expression(const QString &str) {
    _liste = str.mid(1,str.size()-2);
}

QString Expression::toString() const {
    QString str = "'";
    str += _liste;
    str.resize(str.size());
    str += "'";
   return str;
}

Expression* Expression::operator+(Constante* c) {
    Expression* e = new Expression();
    if(typeid(*c)==typeid(Expression)) {
        Expression * ccopy = dynamic_cast<Expression*>(c);
        e->setListe(getListe()+" "+ccopy->getListe()+" +");
    }
    else
        e->setListe(getListe()+" "+c->toString()+" +");
    return e;
}

Expression* Expression::operator-(Constante* c) {
    Expression* e = new Expression();
    if(typeid(*c)==typeid(Expression)) {
        Expression * ccopy = dynamic_cast<Expression*>(c);
        e->setListe(getListe()+" "+ccopy->getListe()+" -");
    }
    else
        e->setListe(getListe()+" "+c->toString()+" -");
    return e;
}

Expression* Expression::operator*(Constante* c) {
    Expression* e = new Expression();
    if(typeid(*c)==typeid(Expression)) {
        Expression * ccopy = dynamic_cast<Expression*>(c);
        e->setListe(getListe()+" "+ccopy->getListe()+" *");
    }
    else
        e->setListe(getListe()+" "+c->toString()+" *");
    return e;
}

Expression* Expression::operator/(Constante* c) {
    Expression* e = new Expression();
    if(typeid(*c)==typeid(Expression)) {
        Expression * ccopy = dynamic_cast<Expression*>(c);
        e->setListe(getListe()+" "+ccopy->getListe()+" /");
    }
    else
        e->setListe(getListe()+" "+c->toString()+" /");
    return e;
}
