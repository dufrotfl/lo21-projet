/*!
 \file nombreNomComplexe.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef NOMBRENONCOMPLEXE_H
#define NOMBRENONCOMPLEXE_H

#include "nombre.h"
#include "math.h"

class NombreComplexe;
class Entier;
class Rationnel;
class Reel;

/*!
 \class NombreNonComplexe
 \brief Classe qui �tend l'interface @link Nombre @endlink et permettant de g�rer des constantes de type non complexe (@link Entier @endlink, @link Rationnel @endlink, @link Reel @endlink).
*/
class NombreNonComplexe : public Nombre {
private:
public:
    /*!
     \brief Destructeur de l'instance de la classe NombreNonComplexe.
    */
    virtual ~NombreNonComplexe() {}
    /*!
     \brief M�thode permettant de faire l'addition entre deux nombres.
     \param nb La deuxi�me op�rande
     \return La somme des deux nombres
    */
    NombreNonComplexe* operator+(NombreNonComplexe* nb);
    /*!
     \brief M�thode permettant de faire la soustraction entre deux nombres.
     \param nb La deuxi�me op�rande
     \return La diff�rence entre les deux nombres
    */
    NombreNonComplexe* operator-(NombreNonComplexe* nb);
    /*!
     \brief M�thode permettant de faire la division entre deux nombres.
     \param nb La deuxi�me op�rande
     \return Le quotient de la division de ces deux nombres
    */
    NombreNonComplexe* operator/(NombreNonComplexe* nb);
    /*!
     \brief M�thode permettant de faire la multiplication entre deux nombres.
     \param nb La deuxi�me op�rande
     \return Le produit des deux nombres
    */
    NombreNonComplexe* operator*(NombreNonComplexe* nb);
    /*!
      \brief M�thode permettant de convertir un @link NombreNonComplexe @endlink en son �quivalent @link Entier @endlink.
      \return Le pointeur vers l' @link Entier @endlink nouvellement cr�e
      */
    virtual Entier* toEntier();
    /*!
      \brief M�thode permettant de convertir un @link NombreNonComplexe @endlink en son �quivalent @link Rationnel @endlink.
      \return Le pointeur vers le @link Rationnel @endlink nouvellement cr�e
      */
    virtual Rationnel* toRationnel();
    /*!
      \brief M�thode permettant de convertir un @link NombreNonComplexe @endlink en son �quivalent @link Reel @endlink.
      \return Le pointeur vers le @link Reel @endlink nouvellement cr�e
      */
    virtual Reel* toReel();
    /*!
      \brief M�thode permettant de r�cup�rer la valeur du @link NombreNonComplexe @endlink sous la forme d'un r�el.
      \return La valeur r�elle
      */
    virtual float getFloatVal() const = 0;
    /*!
      \brief M�thode permettant d'effectuer la puissance d'un nombre.
      \param e Un entier correspondant � la puissance
      */
    virtual void pow(Entier* e) = 0;
};

#endif NOMBRENONCOMPLEXE_H
