/*!
 \file rationnel.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */
#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "nombreNonComplexe.h"

class Reel;
class Entier;
class NombreComplexe;

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
    Rationnel(int n, int d) throw(LogMessage):_numerateur(n), _denominateur(d) {if(d==0) throw LogMessage("Division par 0 non autoris�e.", 1); simplifier();}
    /**
      \brief Cr�e un rationnel avec un constructeur par copie
      \param r Le rationnel � copier
      */
    Rationnel(const Rationnel &r) { _numerateur = r.getNumerateur(); _denominateur = r.getDenominateur(); }
    /*!
      \copydoc Constante::clone()
      */
    Rationnel* clone() const;
    /**
	 \brief Getter du num�rateur de rationnel
	 \return Le num�rateur
	 */
    int getNumerateur() const {return _numerateur;}
	/**
	 \brief Getter du d�nominateur de rationnel
	 \return Le d�nominateur
	 */
    int getDenominateur() const {return _denominateur;}
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
      \copydoc NombreNonComplexe::pow()
      */
    void pow(Entier*);
    /*!
      \copydoc Constante::toString()
      */
    QString toString() const {return QString(QString::number(getNumerateur()) + "/" + QString::number(getDenominateur()));}
    /*!
      \copydoc Nombre::toNombreComplexe()
      */
    NombreComplexe* toNombreComplexe() ;
    /*!
      \copydoc NombreNonComplexe::getFloatVal()
      */
    float getFloatVal() const { return (float)_numerateur/(float)_denominateur;}
    /*!
      \brief M�thode permettant de renvoyer le pgcd des deux nombres pass�s en param�tres
      \param a La premi�re op�rande
      \param b La seconde op�rande
      \return Le pgcd des deux nombres
      */
    int pgcd(int a, int b) const;
    /*!
      \brief M�thode permettant de simplifier l'objet appelant(le rationnel) en appliquant le pgcd et ainsi simplifier le rationnel
      */
    void simplifier();
};

#endif RATIONNEL_H
