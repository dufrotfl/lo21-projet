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
    QString _operateur;
    int _arite;
public:
    /*!
      \brief Cr�e un op�rateur par d�faut
      */
    Operateur();
    /*!
      \brief Cr�e un op�rateur en fonction du param�tre
      \param la chaine repr�sentant l'op�rateur
      */
    Operateur(const QString &op, int ar):_operateur(op), _arite(ar) {}
    /*!
      \brief Getter de la chaine representant l'operateur
      */
    QString getOperateur() const {return _operateur;}
    /*!
      \brief Getter de l'int representant l'arit�
      */
    QString getArite() const {return _arite;}
    /*!
      \copydoc Constante::toString()
      */
    QString toString() const {return _operateur;}
};

#endif OPERATEUR_H
