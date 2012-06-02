/*!
 \file expression.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "QString.h"
#include "qvector.h"
#include "qstringlist.h"
#include "nombre.h"

/*!
  \class Expression
  \brief Classe implémentant l'interface de @link Constante @endlink et permettant la gestion d'un expression
  */
class Expression : public Constante {
private:
    /**<
      Liste des constantes qui composent cette expression
      */
    QVector<Constante*> * _liste;
public:
    /*!
      \brief Crée une expression par défaut
      */
    Expression();
    /*!
      \brief Crée une expression avec les
      */
    Expression(const QString &);

    QVector<Constante*>* getListe() {return _liste;}

    Nombre* eval() const throw(LogMessage);
    /*!
      \copydoc Constance::toString()
      */
    QString toString() const;

    Expression* operator+(Constante*);
    Expression* operator-(Constante*);
    Expression* operator*(Constante*);
    Expression* operator/(Constante*);

};

#endif EXPRESSION_H
