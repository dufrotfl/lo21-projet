/**
 \file logSystem.cpp
 \brief Classe permettant de gerer les logs du programme
 \author Sebastien Fradcourt & Florian Dufrot
 \date 22 Mai 2012
 \version 1.0
 */

#include "logSystem.h"
#include "qstatusbar.h"

LogSystem* LogSystem::_instance= 0;

LogSystem::LogSystem() {
    _fichier = new QFile("fichierLog.txt");
   if(!_fichier->open(QIODevice::ReadWrite | QIODevice::Text))
       return;
   // Si le fichier ne contient pas l'entete alors on l'ajoute
   if(_fichier->size() == 0) {
       _fichier->write(initialisationFichier().toAscii());
       _fichier->flush();
   }
   _fichier->close();
}

LogSystem* LogSystem::getInstance() {
    if(!_instance) _instance = new LogSystem();
    return _instance;
}

void LogSystem::freeInstance() {
    if(!_instance)
        delete _instance;
}

LogSystem::~LogSystem() {
    delete _fichier;
}

void LogSystem::addMessage(const LogMessage & log) {
    if(log.getDegre()==1)
        MainWindow::getInstance()->statusBar()->showMessage("Erreur :     "+log.getMessage(), 5000);
    else if(log.getDegre()==2)
        MainWindow::getInstance()->statusBar()->showMessage("Avertissement :    "+log.getMessage(), 5000);

    if(!_fichier->isOpen())
        _fichier->open(QIODevice::Append | QIODevice::Text);
    // Le message de log que l'on veut insérer
    QString message("\n");
    message+="Date et heure du log: ";
    message.append(log.getDate());
    message+="\tImportance : ";
    message.append(QString::number(log.getDegre()));
    message+= "\n\tContenu :    ";
    message.append(log.getMessage());
    message+= "\n";
    _fichier->write(message.toAscii());
    _fichier->flush();
    _fichier->close();
}

void LogSystem::reset() {
    if(!_fichier->isOpen())
        _fichier->open(QIODevice::ReadWrite | QIODevice::Text);
    _fichier->resize(0);
    _fichier->write(initialisationFichier().toAscii());
    _fichier->close();
}

QString LogSystem::initialisationFichier() {
    QString message("\n");
    time_t temps_act;
    time(&temps_act); // Déterminer le temps actuel en secondes
    message += "---------------------------------------------------------------------------------------\n";
    message += "------------------ Fichier de log de l'application Calculatrice -----------------------\n";
    message += "------------------   Par Sébastien Fradcourt & Florian Dufrot   -----------------------\n";
    message += "------------------   Fichier crée le ";
    message += ctime(&temps_act);
    message.resize(message.size()-1); // Fonction obligatoire afin d'enlever le \n crée par le ctime
    message += "   -----------------------\n";
    message += "---------------------------------------------------------------------------------------\n";

    return message;
}
