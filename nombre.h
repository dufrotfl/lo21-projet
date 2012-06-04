/*!
 \file nombre.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef NOMBRE_H
#define NOMBRE_H
#include "constante.h"

class Reel;
class Expression;
class NombreComplexe;

#define PI 3.14159265

/*!
  \class Nombre
  \brief Etend l'interface @link Constante @endlink pour regrouper tout les valeurs de type numérique sous cette classe et également de proposer les différentes opérations spécifiques aux nombres (opérations arithmétiques, etc)
  */
class Nombre : public Constante {
private:
public:
    /*!
     \brief Destructeur de l'instance de la classe Nombre
     */
    virtual ~Nombre() {}
	/*!
	 \brief Methode permettant de transformer le nombre en son opposé
	*/	
    virtual void sign() = 0;
	/*!
	 \brief Méthode permettant de transformer le nombre en son carré
	*/
    virtual void sqr() = 0;
	/*!
	 \brief Méthode permettant de transformer le nombre en son cube
	*/
    virtual void cube() =0;
    /*!
      \brief Méthode permettant de convertir un @link Nombre @endlink en son équivalent en @link NombreComplexe @endlink
      \return Le pointeur vers le nombreComplexe nouvellement crée
      */
    virtual NombreComplexe* toNombreComplexe() = 0;
    /*!
      \copydoc Expression::operator+()
      */
    Expression* operator+(Expression* e);
    /*!
      \copydoc Expression::operator-()
      */
    Expression* operator-(Expression* e);
    /*!
      \copydoc Expression::operator/()
      */
    Expression* operator/(Expression* e);
    /*!
      \copydoc Expression::operator*()
      */
    Expression* operator*(Expression* e);
    /*!
      \brief Méthode permettant de calculer le cos sur un @link Nombre @endlink
      \return La valeur réelle contenant le cos du @link Nombre @endlink en tenant compte des paramètres utilisateurs (RADIAN ou DEGRES)
      */
    Reel* Acos() throw(LogMessage);
    /*!
      \brief Méthode permettant de calculer le sin sur un @link Nombre @endlink
      \return La valeur réelle contenant le sin du @link Nombre @endlink en tenant compte des paramètres utilisateurs (RADIAN ou DEGRES)
      */
    Reel* Asin() throw(LogMessage);
    /*!
      \brief Méthode permettant d'appliquer la tan sur un @link Nombre @endlink
      \return La valeur réelle contenant la tan du @link Nombre @endlink en tenant compte des paramètres utilisateurs (RADIAN ou DEGRES)
      */
    Reel* Atan() throw(LogMessage);
    /*!
      \brief Méthode permettant de calculer le sinush sur un @link Nombre @endlink
      \return La valeur réelle contenant le sinush du @link Nombre @endlink en tenant compte des paramètres utilisateurs (RADIAN ou DEGRES)
      */
    Reel* Asinh() throw(LogMessage);
    /*!
      \brief Méthode permettant de calculer le cosh sur un @link Nombre @endlink
      \return La valeur réelle contenant le cosh du @link Nombre @endlink en tenant compte des paramètres utilisateurs (RADIAN ou DEGRES)
      */
    Reel* Acosh() throw(LogMessage);
    /*!
      \brief Méthode permettant de calculer le tanh sur un @link Nombre @endlink
      \return La valeur réelle contenant le tanh du @link Nombre @endlink en tenant compte des paramètres utilisateurs (RADIAN ou DEGRES)
      */
    Reel* Atanh() throw(LogMessage);
    /*!
      \brief Méthode permettant de calculer le logarithme népérien  sur un @link Nombre @endlink
      \return La valeur réelle contenant le logarithme népérien du @link Nombre @endlink
      */
    Reel* Aln() throw(LogMessage);
    /*!
      \brief Méthode permettant de calculer le logarithme sur un @link Nombre @endlink
      \return La valeur réelle contenant le logarithme du @link Nombre @endlink
      */
    Reel* Alog() throw(LogMessage);
    /*!
      \brief Méthode permettant de retourner l'inverse d'un @link Nombre @endlink
      \return La valeur réelle contenant l'inverse du @link Nombre @endlink
      */
    Reel* Ainv() throw(LogMessage);
    /*!
      \brief Méthode permettant de calculer la racine d'un @link Nombre @endlink
      \return La valeur réelle contenant la racine du @link Nombre @endlink
      */
    Reel* Asqrt() throw(LogMessage);

};

#endif NOMBRE_H
