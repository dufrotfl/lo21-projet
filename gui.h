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
 \brief Classe principal permettant d'instancier une seule et m�me calculatrice
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
	 \brief Cr�e une instance pour chaque attribut de la classe (except� _instance)
	*/
    Gui();
	/*!
	 \brief Constructeur par copie (On le d�finit ici, afin d'empecher son utilisation)
	*/
    Gui(const Gui &);
	/*!
	 \brief Operateur d'affectation (On le d�finit ici, afin d'empecher son utilisation)
	*/
    void operator=(const Gui &);
	/*!
	 \brief Destructeur des diff�rentes instances de la classe Gui
	*/
    ~Gui();
public:
	/*!
	 \brief M�thode permettant de r�cup�rer l'instance de classe, si celle-ci n'existe pas, la m�thode la cr�e et la renvoie.
	 \return L'instance de la classe Gui
	*/
    static Gui* getInstance();
	/*!
	 \brief M�thode permettant de lib�rer l'instance de classe, si celle-ci n'existe pas, alors rien n'est lib�rer.
	*/
    static void freeInstance();
	/*!
	 \brief M�thode permettant de r�cup�rer la pile
	 \return La pile
	*/
    Pile* getPile();
    /*!
      \brief M�thode permettant de r�cup�rer la mainwindow
      */
    MainWindow* getMainWindow();
	/*!
	 \brief M�thode permettant de charger l'ancien context et d'afficher l'aspect graphique de la calculatrice
	 */
    void exec();
    /*!
      \brief
      */
    void eval();
};

#endif
