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
  \brief Classe impl�mentant l'interface de @link Constante @endlink
  */
class Operateur : public Constante {
private:
    /**<
      Caract�re repr�sentant l'op�rateur
      */
    char * _operateur;
public:
    /*!
      \brief Cr�e un op�rateur par d�faut
      */
    Operateur();
    /*!
      \brief Cr�e un op�rateur en fonction du param�tre
      \param la chaine repr�sentant l'op�rateur
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
