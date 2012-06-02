/*!
 \file nombre.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef NOMBRE_H
#define NOMBRE_H
#include "constante.h"

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
};

#endif NOMBRE_H
