/*!
 \file constante.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "logMessage.h"
#include "settings.h"

/*!
  \class Constante
  \brief Interface permettant de gérer les différents types de valeurs qui peuvent être empilées sur la pile
  */
class Constante {
private:
public:
    /*!
      \brief Destructeur de l'instance de la classe Constante
      */
    virtual ~Constante() {}
    /*!
      \brief Méthode permettant de cloner une constante
      \param Le pointeur vers la constante clonée
      */
    virtual Constante* clone() const = 0;
    /*!
      \brief Fonction permettant de renvoyer une chaine comprenant la valuation de la constante associé, cette fonction est utilisée dans le cadre de l'affichage des constantes dans la pile
      \return La chaine à afficher dans la pile
      */
    virtual QString toString() const =0;
};

#endif CONSTANTE_H
