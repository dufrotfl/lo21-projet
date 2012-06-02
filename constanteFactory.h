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
#include "entier.h"
#include "expression.h"
#include "rationnel.h"
#include "reel.h"
#include "nombreComplexe.h"
#include "operateur.h"
#include "operateur.h"
#include "settings.h"

/*!
 \class ConstanteFactory
 \brief Classe permettant d'instancier des objets de type @link Constante @endlink grâce au design pattern factory
 */
class ConstanteFactory {
public:
	/*!
	 \brief Méthode permettant de crée un objet de type @link Constante @endlinke en lui passant une QString en parametre
	 \param str La chaine à convertir en @link Constante @endlink
	*/
    static Constante* getConstante(const QString & str) throw(LogMessage);
};


#endif CONSTANTEFACTORY_H
