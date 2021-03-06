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
  \brief Interface (utilisant le design pattern composite) permettant de g�rer les diff�rents types de valeurs qui peuvent �tre empil�es sur la pile.
  */
class Constante {
private:
public:
    /*!
      \brief Destructeur de l'instance de la classe Constante.
      */
    virtual ~Constante() {}
    /*!
      \brief M�thode permettant de cloner une constante.
      \param Le pointeur vers la constante clon�e
      */
    virtual Constante* clone() const = 0;
    /*!
      \brief Fonction permettant de renvoyer une chaine comprenant la valuation de la constante associ�, cette fonction est utilis�e dans le cadre de l'affichage des constantes dans la pile.
      \return La chaine � afficher dans la pile
      */
    virtual QString toString() const =0;
};

#endif CONSTANTE_H
