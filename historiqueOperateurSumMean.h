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
  \brief Classe implémentant l'interface @link Historique @endlink et permettant de gérer l'historique des commandes "sum" et "mean"
  */
class HistoriqueOperateurSumMean : public Historique {
    /**<
      Pile contenant l'ensemble des constantes qui sont sommées au cours d'un "sum" ou d'un "mean"
      */
    QStack<Constante*>* _tabConstante;
    /**<
      Le résultat de cette somme ou de cette moyenne
      */
    Constante* _resultat;
public:
    /*!
      \brief Constructeur avec paramètres
      \param La pile contenant l'ensemble des constantes qui sont sommées au cours d'un "sum" ou d'un "mean"
      */
    HistoriqueOperateurSumMean(QStack<Constante*>* c1);
    /*!
      \brief Destructeur de la classe
      */
    ~HistoriqueOperateurSumMean() {delete _tabConstante;}
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

#endif // HISTORIQUEOPERATEURSUMMEAN_H
