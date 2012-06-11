/*!
 \file historiqueOperateurSumMean.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 03 Juin 2012
 \version 1.0
 */

#ifndef HISTORIQUEOPERATEURSUMMEAN_H
#define HISTORIQUEOPERATEURSUMMEAN_H

#include "historique.h"
#include "constante.h"
#include "qstack.h"

/*!
  \class HistoriqueOperateurSumMean
  \brief Classe impl�mentant l'interface @link Historique @endlink et permettant de g�rer l'historique des commandes "sum" et "mean"
  */
class HistoriqueOperateurSumMean : public Historique {
    /**<
      Pile contenant l'ensemble des constantes qui sont somm�es au cours d'un "sum" ou d'un "mean"
      */
    QStack<Constante*>* _tabConstante;
    /**<
      Le r�sultat de cette somme ou de cette moyenne
      */
    Constante* _resultat;
public:
    /*!
      \brief Constructeur avec param�tres
      \param La pile contenant l'ensemble des constantes qui sont somm�es au cours d'un "sum" ou d'un "mean"
      */
    HistoriqueOperateurSumMean(QStack<Constante*>* c1);
    /*!
      \brief Destructeur de la classe
      */
    ~HistoriqueOperateurSumMean() {delete _tabConstante;}
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

#endif // HISTORIQUEOPERATEURSUMMEAN_H
