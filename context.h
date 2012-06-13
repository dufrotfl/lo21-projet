/*!
 \file context.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */
 
#ifndef CONTEXT_H
#define CONTEXT_H

#include "mainwindow.h"
#include <iostream>
#include <fstream>

using namespace std;

/*!
 \class Context
 \brief Classe (utilisant le Design Pattern Singleton) permettant de g�rer l'�criture du context afin de pouvoir le recharger lors de l'ouverture de l'application.
*/
class Context {
private:
	/**<
	 L'unique instance de Context
	*/
    static Context* _instance;
	/*!
	 \brief Constructeur par d�faut.
	*/
    Context();
    /*!
     \brief Contructeur par copie (On le d�finit dans le header afin d'interdire l'utilisation de celui-ci).
     \param c Le context � copier
    */
    Context(const Context& c);
	/*!
	 \brief Operateur d'affectation (On le d�finit dans le header afin d'interdire l'utilisation de celui-ci).
     \param c Le context � copier
	*/
    void operator=(const Context& c);
	/*!
     \brief Destructeur de la classe.
	*/
    ~Context() {}
public:
	/*!
     \brief Getter de l'unique instance de Context, si elle existe pas, on la cr�e.
	 \return L'unique instance de Context
	*/
    static Context* getInstance();
	/*!
     \brief M�thode permettant de lib�rer l'unique instance de Context.
	*/
    static void freeInstance();

	/*!
     \brief M�thode permettant de stocker le contexte en m�moire afin de pouvoir le recharger apr�s.
	*/
    void sauvegardeContext();

    /*!
      \brief M�thode permettant de charger le contexte afin de restaurer les param�tres de la calculatrice et l'�tat de la pile.
      */
    void chargerContext() throw (LogMessage);
};

#endif
