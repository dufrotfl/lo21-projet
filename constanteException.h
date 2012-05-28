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
 \brief Classe permettant de gérer les exceptions générées en rapport avec les objets de type @link Constante @endlink
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
	 \brief Crée une constanteException en initialisant _errorCode avec le paramètre
	 \param errorCode Le code d'erreur
	*/
    ConstanteException(const QString &m, int d):_message(m), _degre(d) {}
};

#endif
