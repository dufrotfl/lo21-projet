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
  \brief Classe impl�mentant l'interface de @link Constante @endlink
  */
class Operateur : public Constante {
private:
    /**<
      Chaine de caract�re repr�sentant l'op�rateur (ex : +,-,/,*,cos, sin,...)
      */
    QString _operateur;
    /**<
      L'arit� de l'op�rateur (0 pour les op�rations sans param�tres comme 'DUP', 1 pour les op�rations unaires et 2 pour les op�rations binaires)
      */
    int _arite;
public:
    /*!
      \brief Cr�e un op�rateur par d�faut
      */
    Operateur();
    /*!
      \brief Cr�e un op�rateur en fonction du param�tre
      \param op La chaine repr�sentant l'op�rateur
      \param ar L'arit� de l'op�rateur
      */
    Operateur(const QString &op, int ar):_operateur(op), _arite(ar) { if(ar <0 || ar>2) throw LogMessage("Impossible d'instancier un op�rateur d'arit� non �gal � 0, 1 ou 2.", 1);}
    /*!
      \copydoc Constante::clone()
      */
    Operateur* clone() const;
    /*!
      \brief Getter de la chaine representant l'operateur
      \return La chaine correspondant � l'op�rateur
      */
    QString getOperateur() const {return _operateur;}
    /*!
      \brief Getter de l'int representant l'arit�
      \return L'arit� de l'op�rateur
      */
    int getArite() const {return _arite;}
    /*!
      \copydoc Constante::toString()
      */
    QString toString() const {return _operateur;}
    /*!
      \brief M�thode permettant d'appeler la bonne m�thode en fonction de l'op�rateur et des deux constantes associ�es
      \param c1 La premi�re op�rande (pr�sente dans le cas d'une op�ration unaire & binaire)
      \param c2 La seconde op�rande (pr�sente dans le cas d'une op�ration binaire)
      \return Le r�sultat de type @link Constante @endlink apr�s avoir appliqu� l'op�ration
      */
    Constante* call(Constante* c1=0, Constante *c2=0);
};

#endif OPERATEUR_H
