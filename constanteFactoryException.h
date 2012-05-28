/*!
 \file constanteFactoryException.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */
 #ifndef CONSTANTEFACTORYEXCEPTION_H
#define CONSTANTEFACTORYEXCEPTION_H

#include <QString>

/*!
 \class ConstanteFactoryException
 \brief Classe permettant de g�rer les exceptions g�n�r�es lors de l'appel des fonctions de ConstanteFactory
*/
class ConstanteFactoryException {
private:
	/**<
	 Le code d'erreur
	*/
    QString _message;
    int _degre;
public:
	/*!
	 \brief Cr�e une constanteFactoryException en initialisant _errorCode avec le param�tre
	 \param errorCode Le code d'erreur
	*/
    ConstanteFactoryException(const QString &m, int d):_message(m), _degre(d) {}
};

#endif
