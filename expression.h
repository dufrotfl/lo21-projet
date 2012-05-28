/*!
 \file expression.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "QString.h"
#include "nombre.h"
#include "qvector.h"
#include "entier.h"

/*!
  \class Expression
  \brief Classe impl�mentant l'interface de @link Constante @endlink et permettant la gestion d'un expression
  */
class Expression : public Constante {
private:
    /**<
      Liste des constantes qui composent cette expression
      */
    QVector<Constante*> _liste;
public:
    /*!
      \brief Cr�e une expression par d�faut
      */
    Expression() {}
    /*!
      \brief Cr�e une expression avec les
      */
    Expression(const QString &) {}
    Nombre* eval() const throw(ConstanteException);
    /*!
      \copydoc Constance::toString()
      */
    QString toString() const;
};

#endif EXPRESSION_H
