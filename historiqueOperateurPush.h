/*!
 \file historiqueOperateurPush.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 03 Juin 2012
 \version 1.0
 */

#ifndef HISTORIQUEOPERATEURPUSH_H
#define HISTORIQUEOPERATEURPUSH_H

#include "historique.h"
#include "constante.h"

/*!
  \class HistoriqueOperateurPush
  \brief Classe impl�mentant l'interface @link Historique @endlink et permettant de g�rer l'historique de tous les push.
  */
class HistoriqueOperateurPush : public Historique {
    /**<
      La constante qui est ins�r�e au cours d'un push
      */
    Constante* _constante1;
public:
    /*!
      \brief Constructeur avec param�tre.
      \param c1 La constante qui est ins�r�e au cours d'un push
      */
    HistoriqueOperateurPush(Constante* c1):_constante1(c1->clone()) {}
    /*!
      \brief Destructeur de la classe.
      */
    ~HistoriqueOperateurPush() {delete _constante1;}
    /*!
      \copydoc Historique::undo()
      */
    void undo();
    /*!
      \copydoc Historique::redo()
      */
    void redo();
};


#endif // HISTORIQUEOPERATEURPUSH_H
