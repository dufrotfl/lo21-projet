/*!
 \file historique.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 03 Juin 2012
 \version 1.0
 */

#ifndef HISTORIQUE_H
#define HISTORIQUE_H

/*!
  \class Historique
  \brief Classe abstraite permettant de gérer des objets de type Historique
  */
class Historique {
public:
    /*!
      \brief Méthode virtuelle pure permettant d'effectuer un "undo" sur la commande courante
      */
    virtual void undo()=0;
    /*!
      \brief Méthode virtuelle pure permettant d'effectuer un "redo" sur la commande courante
      */
    virtual void redo()=0;
};

#endif
