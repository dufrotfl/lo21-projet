/*!
 \file gui.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 24 Mai 2012
 \version 1.0
 */
 
#ifndef GUI_H
#define GUI_H

#include "context.h"
#include "pile.h"
#include "logSystem.h"
#include "logMessage.h"
#include "constanteFactory.h"
#include "settings.h"
#include "mainwindow.h"
#include "constanteException.h"

/*!
 \class Gui
 \brief Classe principal permettant d'instancier une seule et même calculatrice
*/
class Gui {
private:
	/**<
	 La pile de la calculatrice
	*/
    Pile* _pile;
	/**<
	 L'unique Instance de la calculatrice
	*/
    static Gui* _instance;
	/**<
	 La partie graphique de la calculatrice
	*/
    MainWindow* _mainwindow;
	/*!
	 \brief Crée une instance pour chaque attribut de la classe (excepté _instance)
	*/
    Gui();
	/*!
	 \brief Constructeur par copie (On le définit ici, afin d'empecher son utilisation)
	*/
    Gui(const Gui &);
	/*!
	 \brief Operateur d'affectation (On le définit ici, afin d'empecher son utilisation)
	*/
    void operator=(const Gui &);
	/*!
	 \brief Destructeur des différentes instances de la classe Gui
	*/
    ~Gui();
public:
	/*!
	 \brief Méthode permettant de récupérer l'instance de classe, si celle-ci n'existe pas, la méthode la crée et la renvoie.
	 \return L'instance de la classe Gui
	*/
    static Gui* getInstance();
	/*!
	 \brief Méthode permettant de libérer l'instance de classe, si celle-ci n'existe pas, alors rien n'est libérer.
	*/
    static void freeInstance();
	/*!
	 \brief Méthode permettant de récupérer la pile
	 \return La pile
	*/
    Pile* getPile();
    /*!
      \brief Méthode permettant de récupérer la mainwindow
      */
    MainWindow* getMainWindow();
	/*!
	 \brief Méthode permettant de charger l'ancien context et d'afficher l'aspect graphique de la calculatrice
	 */
    void exec();
    /*!
      \brief
      */
    void eval();
};

#endif
