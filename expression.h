/*!
 \file expression.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"
#include "QString.h"
#include "qvector.h"
#include "qstringlist.h"

/*!
  \class Expression
  \brief Classe implémentant l'interface de @link Constante @endlink et permettant la gestion d'un expression
  */
class Expression : public Constante {
private:
    /**<
      Liste des constantes qui composent cette expression
      */
    QString _liste;
public:
    /*!
      \brief Crée une expression par défaut
      */
    Expression();
    /*!
      \brief Crée une expression avec les
      */
    Expression(const QString &);
    /*!
      \copydoc Constante::clone()
      */
    Expression* clone() const;
    /*!
      \brief Méthode permettant de retourner la chaine contenant l'expression
      \return La chaine de l'expression
      */
    QString getListe() const {return _liste;}
    /*!
      \brief Méthode permettant de modifier la chaine contenant l'expression
      \param La nouvelle chaine de l'expression
      */
    void setListe(const QString &str) { _liste=str;}
    /*!
      \copydoc Constance::toString()
      */
    QString toString() const;
    /*!
      \brief Méthode permettant de retourner une expression contenant l'expression appelante, la constante passée en paramètre et ainsi que l'opérateur associé ('+')
      \param c La constante à insérer dans l'expression
      \return L'expression ressortissante de l'opération
      */
    Expression* operator+(Constante* c);
    /*!
      \brief Méthode permettant de retourner une expression contenant l'expression appelante, la constante passée en paramètre et ainsi que l'opérateur associé ('-')
      \param c La constante à insérer dans l'expression
      \return L'expression ressortissante de l'opération
      */
    Expression* operator-(Constante* c);
    /*!
      \brief Méthode permettant de retourner une expression contenant l'expression appelante, la constante passée en paramètre et ainsi que l'opérateur associé ('*')
      \param c La constante à insérer dans l'expression
      \return L'expression ressortissante de l'opération
      */
    Expression* operator*(Constante* c);
    /*!
      \brief Méthode permettant de retourner une expression contenant l'expression appelante, la constante passée en paramètre et ainsi que l'opérateur associé ('/')
      \param c La constante à insérer dans l'expression
      \return L'expression ressortissante de l'opération
      */
    Expression* operator/(Constante* c);

};

#endif EXPRESSION_H
