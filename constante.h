/*!
 \file constante.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "constanteException.h"

/*!
  \class Constante
  \brief Interface permettant de g�rer les diff�rents types de valeurs qui peuvent �tre empil�es sur la pile
  */
class Constante {
private:
public:
    /*!
      \brief Destructeur de l'instance de la classe Constante
      */
    virtual ~Constante() {}
    /*!
      \brief Fonction permettant de renvoyer une chaine comprenant la valuation de la constante associ�, cette fonction est utilis�e dans le cadre de l'affichage des constantes dans la pile
      \return La chaine � afficher dans la pile
      */
    virtual QString toString() const =0;
};

#endif CONSTANTE_H
