#include "expression.h"
#include "logSystem.h"
#include "constanteFactory.h"
#include "qdebug.h"

Expression::Expression(const QString &str) {
    QString strcop = str.mid(1,str.size()-2);
    qDebug() << strcop;
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
          str += _liste->at(i)->toString();
    return str;
}
