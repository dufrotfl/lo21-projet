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
 \brief Classe (utilisant le Design Pattern Singleton) permettant de gérer l'écriture des messages de log dans le fichier correspondant
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
     \brief Constructeur par défaut
	 */
    LogSystem();
    /*!
      \brief Constructeur par copie (ici on ne le définira pas, c'est juste pour empécher la construction par copie)
      \param log Le LogSystem à copier
      */
    LogSystem(const LogSystem& log);
    /*!
      \brief Surcharge de l'opérateur = (ici on ne le définira pas, c'est juste pour empécher la possibilité de faire une affectation concernant LogSystem)
      \param log Le LogSystem à copier
      */
    void operator=(const LogSystem& log);
    /*!
	 \brief Destructeur de l'instance de la classe LogSystem
	 */
    ~LogSystem();
public:
    /*!
      \brief Méthode permettant d'accéder à l'instance de la classe LogSystem
      \return instance de LogSystem
      */
    static LogSystem* getInstance();
    /*!
      \brief Méthode permettant de libérer l'instance de la classe LogSystem
      \return void
      */
    static void freeInstance();
    /*!
     \brief Méthode permettant d'écrire un messageLog dans le fichier de Log
     \param log Le message à ajouter dans le fichier de log mais aussi sur l'interface graphique
     \return void
      */
    void addMessage(const LogMessage& log);
    /*!
      \brief Méthode permettant de réinitialiser le fichier de log
      */
    void reset();
    /*!
      \brief Méthode permettant d'établir l'entête du fichier
      \return La chaine contenant l'entete du fichier
      */
    QString initialisationFichier();
};

#endif // LOGSYSTEM_H
