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
 \brief Classe permettant de gérer la pile d'éléments et également l'historique de cette pile.
*/
class Pile {
private:
    /**<
        La pile contenant les commandes qui ont été effectuées jusqu'à présent
      */
    QStack<Historique*> * _pileUndo;
    /**<
        La pile contenant les commandes qui ont subi un "undo"
      */
    QStack<Historique*> * _pileRedo;
    /**<
      La pile contenant les éléments temporaires de la pile
      */
    QStack<Constante*> * _pileStockage;
    /**<
        La pile contenant les éléments de la pile
      */
    QStack<Constante*> * _pileAffichage;
    /**<
      Nombre d'éléments à afficher
      */
    int _nbElemAffichable;
public:
    /**
     \brief Initialise la pile avec des valeurs par défauts.
    */
    Pile();
    /*!
      \brief Destructeur de la Pile.
      */
    ~Pile();
    /*!
      \brief Méthode permettant d'ajouter un élément à la liste.
      \param constante La constante à ajouter à la liste
      */
    void push(Constante* constante);
    /*!
      \brief Méthode permettant d'enlever un élément de la liste et de la renvoyer.
      \return La constante enlevée de la liste
      */
    Constante* pop() throw (LogMessage);
    /*!
      \brief Méthode permettant de retourner le sommet de la pile.
      \return Le sommet de la pile de type @link Constante @endlink
      */
    Constante* sommet();
    /*!
      \brief Méthode permettant de retourner une QStrinf représentant tout les éléments mis bout à bout, cette méthode est notamment utilisé dans la classe @link Contexte @endlink.
      */
    QString getPileString() const;
    /*!
      \brief Méthode permettant de récupérer la taille de la pile contenant les @link Constante @endlink.
      \return La taille de la pile
      */
    int getPileAffichageSize() const {return _pileAffichage->size();}
    /*!
      \brief Méthode permettant de définir le nombre de @link Constante @endlink qui seront affichées dans la pile d'affichage.
      \param i Le nombre d'élément que l'on veut afficher
      */
    void setNbElemAffichable(int i) {_nbElemAffichable=i;}
    /*!
      \brief Méthode permettant d'ajouter un nouvel élément de type @link Historique @endlink dans la liste des historiques.
      \param e L'élement de type @link Historique @endlink à ajouter
      */
    void ajouteHistorique(Historique* e) {_pileUndo->push(e);}
    /*!
      \brief Méthode permettant de supprimer le dernier élément insérer dans la pile.
      */
    void drop();
    /*!
      \brief Méthode permettant de nettoyer tout les éléments de la pile.
      */
    void clear();
    /*!
      \brief Méthode permettant de dupliquer le sommet de la pile.
      */
    void dup();
    /*!
      \brief Méthode permettant d'échanger l'ordre de deux éléments de la pile.
      \param x L'indice du premier élément
      \param y L'indice du deuxième élément
      */
    void swap(int x,int y);
    /*!
      \brief Méthode permettant de faire la somme des x premiers éléments de la pile.
      \param x Le nombre d'éléments
      */
    void sum(int x);
    /*!
      \brief Méthode permettant de faire la moyenne des x premiers éléments de la pile.
      \param x Le nombre d'éléments
      */
    void mean(int x);
    /*!
      \brief Méthode permettant de rétablir la derniere opération qui a été annulée.
      */
    void redo();
    /*!
      \brief Méthode permettant d'annuler la derniere opération qui a été effectuée.
      */
    void undo();
    /*!
      \brief Méthode permettant d'afficher les éléments contenus dans la pile dans l'interface graphique.
      */
    void affiche();
};

#endif PILE_H
