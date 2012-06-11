/*!
 \file historiqueOperateurSwap.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 03 Juin 2012
 \version 1.0
 */

#ifndef HISTORIQUEOPERATEURSWAP_H
#define HISTORIQUEOPERATEURSWAP_H

#include "historique.h"
#include "entier.h"

/*!
  \class HistoriqueOperateurSwap
  \brief Classe implémentant l'interface @link Historique @endlink et permettant de gérer l'historique de la commande swap
  */
class HistoriqueOperateurSwap : public Historique {
    /**<
      Le premier indice du swap
      */
    Entier* _entier1;
    /**<
      Le second indice du swap
      */
    Entier* _entier2;
public:
    /*!
      \brief Constructeur avec paramètres
      \param c1 Le premier indice du swap
      \param c2 Le second indice du swap
      */
    HistoriqueOperateurSwap(Entier* c1, Entier* c2):_entier1(c1->clone()), _entier2(c2->clone()) {}
    /*!
      \brief Destructeur de la classe
      */
    ~HistoriqueOperateurSwap() {delete _entier1; delete _entier2;}
    /*!
      \copydoc Historique::undo()
      */
    void undo();
    /*!
      \copydoc Historique::redo()
      */
    void redo();
};


#endif // HISTORIQUEOPERATEURSWAP_H
