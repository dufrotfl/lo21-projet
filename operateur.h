/*!
 \file operateur.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */

#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "constante.h"

/*!
  \class Operateur
  \brief Classe implémentant l'interface de @link Constante @endlink
  */
class Operateur : public Constante {
private:
    /**<
      Caractère représentant l'opérateur
      */
    char * _operateur;
public:
    /*!
      \brief Crée un opérateur par défaut
      */
    Operateur();
    /*!
      \brief Crée un opérateur en fonction du paramètre
      \param la chaine représentant l'opérateur
      */
    Operateur(char *);
    /*!
      \brief Getter de la chaine representant l'operateur
      */
    char * getOperateur() const;
    /*!
      \copydoc Constante::toString()
      */
    QString toString() const;
};

#endif OPERATEUR_H
