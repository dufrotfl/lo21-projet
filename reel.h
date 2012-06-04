/*!
 \file reel.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */
 
#ifndef REEL_H
#define REEL_H

#include "nombreNonComplexe.h"

class Rationnel;
class Entier;
class NombreComplexe;

/*!
 \class Reel
 \brief Classe impl�mentant l'interface de @link NombreNonComplexe @endlink
*/
class Reel : public NombreNonComplexe {
private:
	/**<
	 Valeur du r�el
	*/
    float _val;
public:
    ~Reel() {}
	/**
	 \brief Cr�e un r�el avec les valeurs par d�faut 
	*/
    Reel() : _val(0.0) {}
	/**
	 \brief Cr�e un r�el avec la valeur pass�e en param�tre
	 \param val La valeur du r�el
	*/
    Reel(float val) : _val(val) {}
    /**
      \brief Cr�e un r�el avec un constructeur par copie
      \param r Le r�el � copier
      */
    Reel(const Reel &r) { _val = r.getVal(); }
	/**
	 \brief Getter de la valeur du r�el
	 \return La valeur du r�el
	 */
    float getVal() const {return _val;}
	/*!
	 \copydoc Nombre::sign()
	*/
    void sign() { _val *= -1;}
	/*!
	 \copydoc Nombre::sqr()
	*/
    void sqr() { _val *= _val;}
	/*!
	 \copydoc Nombre::cube()
    */
    void cube() { _val *= _val*_val;}
    /*!
      \copydoc Constante::toString()
      */
    QString toString() const {return QString(QString::number(getVal()));}
    /*!
      \copydoc Nombre::toNombreComplexe()
      */
    NombreComplexe* toNombreComplexe();
    /*!
      \copydoc NombreNonComplexe::getFloatVal()
      */
    float getFloatVal() const {return _val;}
};

#endif REEL_H
