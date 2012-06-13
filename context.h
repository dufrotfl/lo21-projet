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
 \brief Classe (utilisant le Design Pattern Singleton) permettant de gérer l'écriture du context afin de pouvoir le recharger lors de l'ouverture de l'application.
*/
class Context {
private:
	/**<
	 L'unique instance de Context
	*/
    static Context* _instance;
	/*!
	 \brief Constructeur par défaut.
	*/
    Context();
    /*!
     \brief Contructeur par copie (On le définit dans le header afin d'interdire l'utilisation de celui-ci).
     \param c Le context à copier
    */
    Context(const Context& c);
	/*!
	 \brief Operateur d'affectation (On le définit dans le header afin d'interdire l'utilisation de celui-ci).
     \param c Le context à copier
	*/
    void operator=(const Context& c);
	/*!
     \brief Destructeur de la classe.
	*/
    ~Context() {}
public:
	/*!
     \brief Getter de l'unique instance de Context, si elle existe pas, on la crée.
	 \return L'unique instance de Context
	*/
    static Context* getInstance();
	/*!
     \brief Méthode permettant de libérer l'unique instance de Context.
	*/
    static void freeInstance();

	/*!
     \brief Méthode permettant de stocker le contexte en mémoire afin de pouvoir le recharger après.
	*/
    void sauvegardeContext();

    /*!
      \brief Méthode permettant de charger le contexte afin de restaurer les paramètres de la calculatrice et l'état de la pile.
      */
    void chargerContext() throw (LogMessage);
};

#endif
