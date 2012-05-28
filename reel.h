/*!
 \file reel.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */
 
#ifndef REEL_H
#define REEL_H

#include "nombreNonComplexe.h"

/*!
 \class Reel
 \brief Classe implémentant l'interface de @link NombreNonComplexe @endlink
*/
class Reel : public NombreNonComplexe {
private:
	/**<
	 Valeur du réel
	*/
    float _val;
public:
    ~Reel() {}
	/**
	 \brief Crée un réel avec les valeurs par défaut 
	*/
    Reel() : _val(0.0) {}
	/**
	 \brief Crée un réel avec la valeur passée en paramètre
	 \param val La valeur du réel
	*/
    Reel(float val) : _val(val) {}
	/**
	 \brief Getter de la valeur du réel
	 \return La valeur du réel
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
	 \copydoc Nombre::operator+(Nombre)
	*/
    Nombre& operator+(const Nombre&) const {return Reel();}
	/*!
	 \copydoc Nombre::operator-(Nombre)
	*/
    Nombre& operator-(const Nombre&) const {return Reel();}
	/*!
	 \copydoc Nombre::operator/(Nombre)
	*/
    Nombre& operator/(const Nombre&) const {return Reel();}
	/*!
	 \copydoc Nombre::operator*(Nombre)
	*/
    Nombre& operator*(const Nombre&) const {return Reel();}
    /*!
      \copydoc Constante::toString()
      */
    QString toString() const;
};

#endif REEL_H
