/*!
 \file operateur.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "constante.h"
#include "nombre.h"
#include "expression.h"

/*!
  \class Operateur
  \brief Classe implémentant l'interface de @link Constante @endlink
  */
class Operateur : public Constante {
private:
    /**<
      Chaine de caractère représentant l'opérateur (ex : +,-,/,*,cos, sin,...)
      */
    QString _operateur;
    /**<
      L'arité de l'opérateur (0 pour les opérations sans paramètres comme 'DUP', 1 pour les opérations unaires et 2 pour les opérations binaires)
      */
    int _arite;
public:
    /*!
      \brief Crée un opérateur par défaut
      */
    Operateur();
    /*!
      \brief Crée un opérateur en fonction du paramètre
      \param la chaine représentant l'opérateur
      */
    Operateur(const QString &op, int ar):_operateur(op), _arite(ar) {}
    /*!
      \brief Getter de la chaine representant l'operateur
      */
    QString getOperateur() const {return _operateur;}
    /*!
      \brief Getter de l'int representant l'arité
      */
    int getArite() const {return _arite;}
    /*!
      \copydoc Constante::toString()
      */
    QString toString() const {return _operateur;}
    /*!
      \brief Méthode permettant d'appeler la bonne méthode en fonction de l'opérateur et des deux constantes associées
      \param c1 La première opérande (présente dans le cas d'une opération unaire & binaire)
      \param c2 La seconde opérande (présente dans le cas d'une opération binaire)
      \return Le résultat de type @link Constante @endlink après avoir appliqué l'opération
      */
    Constante* call(Constante* c1=0, Constante *c2=0);
};

#endif OPERATEUR_H
