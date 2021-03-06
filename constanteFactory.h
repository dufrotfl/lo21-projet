/**
 \file constanteFactory.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 22 Mai 2012
 \version 1.0
 */

#ifndef CONSTANTEFACTORY_H
#define CONSTANTEFACTORY_H

#include <QString>
#include <QRegExp>
#include "constante.h"

/*!
 \class ConstanteFactory
 \brief Classe (utilisant le Design Pattern Factory) permettant d'instancier des objets de type @link Constante @endlink.
 */
class ConstanteFactory {
public:
	/*!
	 \brief M�thode permettant de cr�e un objet de type @link Constante @endlinke en lui passant une QString en parametre.
	 \param str La chaine � convertir en @link Constante @endlink
	*/
    static Constante* getConstante(const QString & str) throw(LogMessage);
};


#endif CONSTANTEFACTORY_H
