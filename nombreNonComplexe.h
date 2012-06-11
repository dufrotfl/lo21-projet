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
 \brief Classe qui étend l'interface @link Nombre @endlink 
*/
class NombreNonComplexe : public Nombre {
private:
public:
    /*!
     \brief Destructeur de l'instance de la classe NombreNonComplexe
    */
    virtual ~NombreNonComplexe() {}
    /*!
     \brief Méthode permettant de faire l'addition entre deux nombres
     \param nombre La deuxième opérande
     \return La somme des deux nombres
    */
    NombreNonComplexe* operator+(NombreNonComplexe*);
    /*!
     \brief Méthode permettant de faire la soustraction entre deux nombres
     \param nombre La deuxième opérande
     \return La différence entre les deux nombres
    */
    NombreNonComplexe* operator-(NombreNonComplexe*);
    /*!
     \brief Méthode permettant de faire la division entre deux nombres
     \param nombre La deuxième opérande
     \return Le quotient de la division de ces deux nombres
    */
    NombreNonComplexe* operator/(NombreNonComplexe*);
    /*!
     \brief Méthode permettant de faire la multiplication entre deux nombres
     \param nombre La deuxième opérande
     \return Le produit des deux nombres
    */
    NombreNonComplexe* operator*(NombreNonComplexe*);
    /*!
      \brief Méthode permettant de convertir un @link NombreNonComplexe @endlink en son équivalent @link Entier @endlink
      \return Le pointeur vers l' @link Entier @endlink nouvellement crée
      */
    virtual Entier* toEntier();
    /*!
      \brief Méthode permettant de convertir un @link NombreNonComplexe @endlink en son équivalent @link Rationnel @endlink
      \return Le pointeur vers le @link Rationnel @endlink nouvellement crée
      */
    virtual Rationnel* toRationnel();
    /*!
      \brief Méthode permettant de convertir un @link NombreNonComplexe @endlink en son équivalent @link Reel @endlink
      \return Le pointeur vers le @link Reel @endlink nouvellement crée
      */
    virtual Reel* toReel();
    /*!
      \brief Méthode permettant de récupérer la valeur du @link NombreNonComplexe @endlink sous la forme d'un réel
      \return La valeur réelle
      */
    virtual float getFloatVal() const = 0;

    /*!
      \brief Méthode permettant d'effectuer la puissance d'un nombre
      \param Un entier correspondant à la puissance
      */
    virtual void pow(Entier*) = 0;
};

#endif NOMBRENONCOMPLEXE_H
