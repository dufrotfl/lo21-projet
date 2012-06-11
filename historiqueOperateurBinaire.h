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
  \brief Classe impl�mentant l'interface @link Historique @endlink et permettant de g�rer l'historique de toute les commandes binaires
  */
class HistoriqueOperateurBinaire : public Historique {
    /**<
        La premi�re op�rande de la commande
      */
    Constante* _constante1;
    /**<
        La seconde op�rande de la commande
      */
    Constante* _constante2;
    /**<
        Le r�sultat de la commande
      */
    Constante* _resultat;
public:
    /*!
      \brief Constructeur avec parametres
      \param c1 La premi�re op�rande de la commande
      \param c2 La seconde op�rande de la commande
      */
    HistoriqueOperateurBinaire(Constante* c1, Constante* c2):_constante1(c1->clone()), _constante2(c2->clone()) {}
    /*!
      \brief Destructeur de la classe
      */
    ~HistoriqueOperateurBinaire() {delete _constante1; delete _constante2;}
    /*!
      \brief M�thode permettant de stocker le r�sultat de la commande dans l'attribut _resultat de la classe
      \param res Le r�sultat de l'op�ration
      \return Le r�sultat de l'op�ration
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
