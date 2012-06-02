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
    QString _operateur;
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
    QString getArite() const {return _arite;}
    /*!
      \copydoc Constante::toString()
      */
    QString toString() const {return _operateur;}
};

#endif OPERATEUR_H
