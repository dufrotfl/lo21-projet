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
  \brief Classe impl�mentant l'interface @link Historique @endlink et permettant de g�rer l'historique des commandes unaires
  */
class HistoriqueOperateurUnaire : public Historique {
    /**<
      L'op�rande de l'op�ration
      */
    Constante* _constante1;
    /**<
      Le r�sultat de l'op�ration
      */
    Constante* _resultat;
public:
    /*!
      \brief Le constructeur avec param�tres
      \param c1 L'op�rande de l'op�ration
      */
    HistoriqueOperateurUnaire(Constante* c1):_constante1(c1->clone()) {}
    /*!
      \brief Destructeur de la classe
      */
    ~HistoriqueOperateurUnaire() {delete _constante1;}
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
