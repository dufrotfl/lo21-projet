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
      \brief Crée un réel avec un constructeur par copie
      \param r Le réel à copier
      */
    Reel(const Reel &r) { _val = r.getVal(); }
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
