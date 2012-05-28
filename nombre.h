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
  \brief Etend l'interface @link Constante @endlink pour regrouper tout les valeurs de type num�rique sous cette classe et �galement de proposer les diff�rentes op�rations sp�cifiques aux nombres (op�rations arithm�tiques, etc)
  */
class Nombre : public Constante {
private:
public:
    /*!
     \brief Destructeur de l'instance de la classe Nombre
     */
    virtual ~Nombre() {}
	/*!
	 \brief Methode permettant de transformer le nombre en son oppos�
	*/	
    virtual void sign() = 0;
	/*!
	 \brief M�thode permettant de transformer le nombre en son carr�
	*/
    virtual void sqr() = 0;
	/*!
	 \brief M�thode permettant de transformer le nombre en son cube
	*/
    virtual void cube() =0;
	/*!
	 \brief M�thode permettant de faire l'addition entre deux nombres
	 \param nombre La deuxi�me op�rande
	 \return La somme des deux nombres
	*/
    virtual Nombre& operator+(const Nombre& nombre) const = 0;
	/*!
	 \brief M�thode permettant de faire la soustraction entre deux nombres
	 \param nombre La deuxi�me op�rande
	 \return La diff�rence entre les deux nombres
	*/
    virtual Nombre& operator-(const Nombre& nombre) const = 0;
	/*!
	 \brief M�thode permettant de faire la division entre deux nombres
	 \param nombre La deuxi�me op�rande
	 \return Le quotient de la division de ces deux nombres
	*/
    virtual Nombre& operator/(const Nombre& nombre) const = 0;
	/*!
	 \brief M�thode permettant de faire la multiplication entre deux nombres
	 \param nombre La deuxi�me op�rande
	 \return Le produit des deux nombres
	*/
    virtual Nombre& operator*(const Nombre& nombre) const = 0;
};

#endif NOMBRE_H
