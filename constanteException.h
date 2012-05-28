/*!
 \file constanteException.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */
 #ifndef CONSTANTEEXCEPTION_H
#define CONSTANTEEXCEPTION_H

#include <QString>


/*!
 \class ConstanteException
 \brief Classe permettant de g�rer les exceptions g�n�r�es en rapport avec les objets de type @link Constante @endlink
*/
class ConstanteException {
private:
	/**<
	 Le code d'erreur
	*/
    QString _message;
    int _degre;
public:
	/*!
	 \brief Cr�e une constanteException en initialisant _errorCode avec le param�tre
	 \param errorCode Le code d'erreur
	*/
    ConstanteException(const QString &m, int d):_message(m), _degre(d) {}
};

#endif
