/*!
 \file nombreComplexe.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */
#ifndef NOMBRECOMPLEXE_H
#define NOMBRECOMPLEXE_H

#include "nombreNonComplexe.h"


/*!
 \class Classe implémentant l'interface @link Nombre @endlink 
*/
class NombreComplexe : public Nombre {
private:
	/**<
	 Le pointeur de type @link NombreNonComplexe @endlink vers la partie réelle du nombre complexe
	*/
    NombreNonComplexe* _reel;
	/**<
	 Le pointeur de type @link NombreNonComplexe @endlink vers la partie imaginaire du nombre complexe
	*/
    NombreNonComplexe* _img;
public:
	/*!
	 \brief Crée un nombre complexe
	*/
    NombreComplexe() {}
	/*!
	 \brief Crée un nombre complexe
	 \param reel Partie réelle du nombre complexe
	 \param img Partie imaginaire du nombre complexe
	 */
    NombreComplexe(NombreNonComplexe* reel, NombreNonComplexe* img) : _reel(reel), _img(img) {}
    /*!
	 \brief Destructeur de l'instance de la classe NombreComplexe
	*/
    ~NombreComplexe();
	/*!
	 \brief Getter de la partie réelle du nombre complexe
	 \return La partie réelle du nombre complexe
	 */
    NombreNonComplexe* getReel() const { return _reel; }
	/*!
	 \brief Getter de la partie imaginaire du nombre complexe
	 \return La partie imaginaire du nombre complexe
	 */
    NombreNonComplexe* getImg() const { return _img; }
	/*!
	 \copydoc Nombre::sign()
	*/
    void sign();
	/*!
	 \copydoc Nombre::sqr()
	*/
    void sqr();
	/*!
	 \copydoc Nombre::cube()
	*/
    void cube();
	/*!
     \copydoc NombreComplexe::operator+(NombreComplexe)
	*/
    NombreComplexe* operator+(NombreComplexe*);
	/*!
     \copydoc NombreComplexe::operator-(NombreComplexe)
	*/
    NombreComplexe* operator-(NombreComplexe*);
	/*!
     \copydoc NombreComplexe::operator/(NombreComplexe)
	*/
    NombreComplexe* operator/(NombreComplexe*);
	/*!
     \copydoc NombreComplexe::operator*(NombreComplexe)
	*/
    NombreComplexe* operator*(NombreComplexe*);
    /*!
      \copydoc Nombre::toString()
      */
    QString toString() const;
    /*!
      \copydoc Nombre::toNombreComplexe()
      */
    NombreComplexe* toNombreComplexe() {return this;}
};


#endif
