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
 \brief Classe qui �tend l'interface @link Nombre @endlink 
*/
class NombreNonComplexe : public Nombre {
private:
public:
    /*!
     \brief Destructeur de l'instance de la classe NombreNonComplexe
    */
    virtual ~NombreNonComplexe() {}
    /*!
     \brief M�thode permettant de faire l'addition entre deux nombres
     \param nombre La deuxi�me op�rande
     \return La somme des deux nombres
    */
    NombreNonComplexe* operator+(NombreNonComplexe*);
    /*!
     \brief M�thode permettant de faire la soustraction entre deux nombres
     \param nombre La deuxi�me op�rande
     \return La diff�rence entre les deux nombres
    */
    NombreNonComplexe* operator-(NombreNonComplexe*);
    /*!
     \brief M�thode permettant de faire la division entre deux nombres
     \param nombre La deuxi�me op�rande
     \return Le quotient de la division de ces deux nombres
    */
    NombreNonComplexe* operator/(NombreNonComplexe*);
    /*!
     \brief M�thode permettant de faire la multiplication entre deux nombres
     \param nombre La deuxi�me op�rande
     \return Le produit des deux nombres
    */
    NombreNonComplexe* operator*(NombreNonComplexe*);

    virtual NombreComplexe* toNombreComplexe() = 0;
    virtual Entier* toEntier();
    virtual Rationnel* toRationnel();
    virtual Reel* toReel();
    virtual float getFloatVal() const = 0;
};

#endif NOMBRENONCOMPLEXE_H
