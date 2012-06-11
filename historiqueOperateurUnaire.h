/*!
 \file historiqueOperateurUnaire.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 03 Juin 2012
 \version 1.0
 */

#ifndef HISTORIQUEOPERATEURUNAIRE_H
#define HISTORIQUEOPERATEURUNAIRE_H

#include "historique.h"
#include "constante.h"

/*!
  \class HistoriqueOperateurUnaire
  \brief Classe implémentant l'interface @link Historique @endlink et permettant de gérer l'historique des commandes unaires
  */
class HistoriqueOperateurUnaire : public Historique {
    /**<
      L'opérande de l'opération
      */
    Constante* _constante1;
    /**<
      Le résultat de l'opération
      */
    Constante* _resultat;
public:
    /*!
      \brief Le constructeur avec paramètres
      \param c1 L'opérande de l'opération
      */
    HistoriqueOperateurUnaire(Constante* c1):_constante1(c1->clone()) {}
    /*!
      \brief Destructeur de la classe
      */
    ~HistoriqueOperateurUnaire() {delete _constante1;}
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
