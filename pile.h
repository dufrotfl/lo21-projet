/*!
 \file pile.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef PILE_H
#define PILE_H
#include "constante.h"
#include "QStack.h"
#include "entier.h"
#include "logMessage.h"
#include "historique.h"

/*!
 \class Pile
 \brief Classe permettant de g�rer la pile d'�l�ments et �galement l'historique de cette pile.
*/
class Pile {
private:
    /**<
        La pile contenant les commandes qui ont �t� effectu�es jusqu'� pr�sent
      */
    QStack<Historique*> * _pileUndo;
    /**<
        La pile contenant les commandes qui ont subi un "undo"
      */
    QStack<Historique*> * _pileRedo;
    /**<
      La pile contenant les �l�ments temporaires de la pile
      */
    QStack<Constante*> * _pileStockage;
    /**<
        La pile contenant les �l�ments de la pile
      */
    QStack<Constante*> * _pileAffichage;
    /**<
      Nombre d'�l�ments � afficher
      */
    int _nbElemAffichable;
public:
    /**
     \brief Initialise la pile avec des valeurs par d�fauts.
    */
    Pile();
    /*!
      \brief Destructeur de la Pile.
      */
    ~Pile();
    /*!
      \brief M�thode permettant d'ajouter un �l�ment � la liste.
      \param constante La constante � ajouter � la liste
      */
    void push(Constante* constante);
    /*!
      \brief M�thode permettant d'enlever un �l�ment de la liste et de la renvoyer.
      \return La constante enlev�e de la liste
      */
    Constante* pop() throw (LogMessage);
    /*!
      \brief M�thode permettant de retourner le sommet de la pile.
      \return Le sommet de la pile de type @link Constante @endlink
      */
    Constante* sommet();
    /*!
      \brief M�thode permettant de retourner une QStrinf repr�sentant tout les �l�ments mis bout � bout, cette m�thode est notamment utilis� dans la classe @link Contexte @endlink.
      */
    QString getPileString() const;
    /*!
      \brief M�thode permettant de r�cup�rer la taille de la pile contenant les @link Constante @endlink.
      \return La taille de la pile
      */
    int getPileAffichageSize() const {return _pileAffichage->size();}
    /*!
      \brief M�thode permettant de d�finir le nombre de @link Constante @endlink qui seront affich�es dans la pile d'affichage.
      \param i Le nombre d'�l�ment que l'on veut afficher
      */
    void setNbElemAffichable(int i) {_nbElemAffichable=i;}
    /*!
      \brief M�thode permettant d'ajouter un nouvel �l�ment de type @link Historique @endlink dans la liste des historiques.
      \param e L'�lement de type @link Historique @endlink � ajouter
      */
    void ajouteHistorique(Historique* e) {_pileUndo->push(e);}
    /*!
      \brief M�thode permettant de supprimer le dernier �l�ment ins�rer dans la pile.
      */
    void drop();
    /*!
      \brief M�thode permettant de nettoyer tout les �l�ments de la pile.
      */
    void clear();
    /*!
      \brief M�thode permettant de dupliquer le sommet de la pile.
      */
    void dup();
    /*!
      \brief M�thode permettant d'�changer l'ordre de deux �l�ments de la pile.
      \param x L'indice du premier �l�ment
      \param y L'indice du deuxi�me �l�ment
      */
    void swap(int x,int y);
    /*!
      \brief M�thode permettant de faire la somme des x premiers �l�ments de la pile.
      \param x Le nombre d'�l�ments
      */
    void sum(int x);
    /*!
      \brief M�thode permettant de faire la moyenne des x premiers �l�ments de la pile.
      \param x Le nombre d'�l�ments
      */
    void mean(int x);
    /*!
      \brief M�thode permettant de r�tablir la derniere op�ration qui a �t� annul�e.
      */
    void redo();
    /*!
      \brief M�thode permettant d'annuler la derniere op�ration qui a �t� effectu�e.
      */
    void undo();
    /*!
      \brief M�thode permettant d'afficher les �l�ments contenus dans la pile dans l'interface graphique.
      */
    void affiche();
};

#endif PILE_H
