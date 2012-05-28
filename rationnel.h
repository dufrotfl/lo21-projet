/*!
 \file rationnel.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */
#ifndef RATIONNEL_H
#define RATIONNEL_H
#include "nombreNonComplexe.h"

/*!
 \class Rationnel
 \brief Classe impl�mentant l'interface de @link NombreNonComplexe @endlink
*/
class Rationnel : public NombreNonComplexe {
private:
	/**<
	 Le num�rateur du rationnel
	*/
    int _numerateur;
	/**<
	 Le d�nominateur du rationnel
	*/
    int _denominateur;
public:
    ~Rationnel() {}
	/**
	 \brief Cr�e un rationnel avec les valeurs par d�faut 
	*/
    Rationnel():_numerateur(0),_denominateur(1) {}
	/**
	 \brief Cr�e un rationnel avec les valeurs pass�es en param�tres
	 \param n Le num�rateur du rationnel
	 \param d Le d�nominateur du rationnel
	*/
    Rationnel(int n, int d) throw(ConstanteException):_numerateur(n), _denominateur(d) {if(d==0) throw new ConstanteException("Division par 0 non autoris�e", 1);}
    /**
	 \brief Getter du num�rateur de rationnel
	 \return Le num�rateur
	 */
    int getNumerateur() const;
	/**
	 \brief Getter du d�nominateur de rationnel
	 \return Le d�nominateur
	 */
    int getDenominateur() const;
    /*!
	 \copydoc Nombre::sign()
	*/
    void sign() { _numerateur *= -1;}
	/*!
	 \copydoc Nombre::sqr()
	*/
    void sqr() { _numerateur *= _numerateur; _denominateur *= _denominateur;}
	/*!
	 \copydoc Nombre::cube()
	*/
    void cube() { _numerateur *= _numerateur*_numerateur; _denominateur *= _denominateur*_denominateur; }
	/*!
	 \copydoc Nombre::operator+(Nombre)
	*/
    Nombre& operator+(const Nombre&) const {return Rationnel();}
	/*!
	 \copydoc Nombre::operator-(Nombre)
	*/
    Nombre& operator-(const Nombre&) const {return Rationnel();}
	/*!
	 \copydoc Nombre::operator/(Nombre)
	*/
    Nombre& operator/(const Nombre&) const {return Rationnel();}
	/*!
	 \copydoc Nombre::operator*(Nombre)
	*/
    Nombre& operator*(const Nombre&) const {return Rationnel();}
    /*!
      \copydoc Constante::toString()
      */
    QString toString() const;
};

#endif RATIONNEL_H
