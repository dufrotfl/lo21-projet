/**
 \file logSystem.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 22 Mai 2012
 \version 1.0
 */

#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include "logMessage.h"
#include "qfile.h"
#include "QTextStream.h"
#include "mainwindow.h"

/*!
 \class LogSystem
 \brief Classe (utilisant le Design Pattern Singleton) permettant de g�rer l'�criture des messages de log dans le fichier correspondant
 */
class LogSystem {
private :
    /**<
      Instance de LogSystem
      */
    static LogSystem* _instance;
    /**<
      Fichier de log
      */
    QFile* _fichier;
    /*!
     \brief Constructeur par d�faut
	 */
    LogSystem();
    /*!
      \brief Constructeur par copie (ici on ne le d�finira pas, c'est juste pour emp�cher la construction par copie)
      \param log Le LogSystem � copier
      */
    LogSystem(const LogSystem& log);
    /*!
      \brief Surcharge de l'op�rateur = (ici on ne le d�finira pas, c'est juste pour emp�cher la possibilit� de faire une affectation concernant LogSystem)
      \param log Le LogSystem � copier
      */
    void operator=(const LogSystem& log);
    /*!
	 \brief Destructeur de l'instance de la classe LogSystem
	 */
    ~LogSystem();
public:
    /*!
      \brief M�thode permettant d'acc�der � l'instance de la classe LogSystem
      \return instance de LogSystem
      */
    static LogSystem* getInstance();
    /*!
      \brief M�thode permettant de lib�rer l'instance de la classe LogSystem
      \return void
      */
    static void freeInstance();
    /*!
     \brief M�thode permettant d'�crire un messageLog dans le fichier de Log
     \param log Le message � ajouter dans le fichier de log mais aussi sur l'interface graphique
     \return void
      */
    void addMessage(const LogMessage& log);
    /*!
      \brief M�thode permettant de r�initialiser le fichier de log
      */
    void reset();
    /*!
      \brief M�thode permettant d'�tablir l'ent�te du fichier
      \return La chaine contenant l'entete du fichier
      */
    QString initialisationFichier();
};

#endif // LOGSYSTEM_H
