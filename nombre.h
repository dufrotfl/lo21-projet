/*!
 \file nombre.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef NOMBRE_H
#define NOMBRE_H
#include "constante.h"

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
	 \brief Méthode permettant de faire l'addition entre deux nombres
	 \param nombre La deuxième opérande
	 \return La somme des deux nombres
	*/
    virtual Nombre& operator+(const Nombre& nombre) const = 0;
	/*!
	 \brief Méthode permettant de faire la soustraction entre deux nombres
	 \param nombre La deuxième opérande
	 \return La différence entre les deux nombres
	*/
    virtual Nombre& operator-(const Nombre& nombre) const = 0;
	/*!
	 \brief Méthode permettant de faire la division entre deux nombres
	 \param nombre La deuxième opérande
	 \return Le quotient de la division de ces deux nombres
	*/
    virtual Nombre& operator/(const Nombre& nombre) const = 0;
	/*!
	 \brief Méthode permettant de faire la multiplication entre deux nombres
	 \param nombre La deuxième opérande
	 \return Le produit des deux nombres
	*/
    virtual Nombre& operator*(const Nombre& nombre) const = 0;
};

#endif NOMBRE_H
