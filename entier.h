/*!
 \file entier.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */
#ifndef ENTIER_H
#define ENTIER_H

#include "nombreNonComplexe.h"

class Reel;
class Rationnel;
class NombreComplexe;

/*!
 \class Entier
 \brief Classe impl�mentant l'interface de @link NombreNonComplexe @endlink
*/
class Entier : public NombreNonComplexe {
private:
	/**<
	 La valeur de l'entier
	*/
    int _val;
public:
    ~Entier() {}
	/**
	 \brief Cr�e un entier avec une valeur par d�faut 
	*/
    Entier():_val(0) {}
	/**
	 \brief Cr�e un entier avec la valeur pass�e en param�tre
     \param v La valeur de l'entier
	*/
    Entier(int v):_val(v) {}

    /**
      \brief Cr�e un entier par constructeur par copie
      \param e L'entier � copier
      */
    Entier(const Entier &e) { _val = e.getVal(); }

    void operator=(NombreNonComplexe* nnc);
	/**
	 \brief Getter de la valeur de l'entier
	 \return La valeur de l'entier
	 */
    int getVal() const {return _val;}
	/**
	 \brief M�thode permettant de transformer le nombre en sa factorielle
	 */
    void fact() {for(int val_copy=_val-1;val_copy>2; val_copy--) _val*=val_copy;}
	/**
	 \brief M�thode permettant de transformer le nombre en son reste de la division du nombre par m
	 \param m Le diviseur
	 */
    void mod(int m)  {_val = _val%m;}
    /*!
	 \copydoc Nombre::sign()
	*/
	void sign()  {_val*=-1;}
	/*!
	 \copydoc Nombre::sqr()
	*/
    void sqr() {_val*=_val;}
	/*!
	 \copydoc Nombre::cube()
	*/
    void cube() {_val*=_val*_val;}

    float getFloatVal() const { return (float)_val;}

    /*!
      \copydoc Constante::toString()
      */
    QString toString() const {return QString(QString::number(getVal())); }
    NombreComplexe* toNombreComplexe() ;
};

#endif ENTIER_H
