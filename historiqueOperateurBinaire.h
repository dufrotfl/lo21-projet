/*!
 \file historiqueOperateurBinaire.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 03 Juin 2012
 \version 1.0
 */

#ifndef HISTORIQUEOPERATEURBINAIRE_H
#define HISTORIQUEOPERATEURBINAIRE_H

#include "historique.h"
#include "constante.h"

/*!
  \class HistoriqueOperateurBinaire
  \brief Classe implémentant l'interface @link Historique @endlink et permettant de gérer l'historique de toute les commandes binaires
  */
class HistoriqueOperateurBinaire : public Historique {
    /**<
        La première opérande de la commande
      */
    Constante* _constante1;
    /**<
        La seconde opérande de la commande
      */
    Constante* _constante2;
    /**<
        Le résultat de la commande
      */
    Constante* _resultat;
public:
    /*!
      \brief Constructeur avec parametres
      \param c1 La première opérande de la commande
      \param c2 La seconde opérande de la commande
      */
    HistoriqueOperateurBinaire(Constante* c1, Constante* c2):_constante1(c1->clone()), _constante2(c2->clone()) {}
    /*!
      \brief Destructeur de la classe
      */
    ~HistoriqueOperateurBinaire() {delete _constante1; delete _constante2;}
    /*!
      \brief Méthode permettant de stocker le résultat de la commande dans l'attribut _resultat de la classe
      \param res Le résultat de l'opération
      \return Le résultat de l'opération
      */
    Constante* setResultat(Constante* res) {_resultat=res->clone(); return _resultat;}
    /*!
      \copydoc Historique::undo()
      */
    void undo();
    /*!
      \copydoc Historique::redo()
      */
    void redo();
};

#endif
