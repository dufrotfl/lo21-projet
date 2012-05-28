/**
 \file logMessage.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 22 Mai 2012
 \version 1.0
 */


#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H
#include <QString>
#include <time.h>

/*!
 \class LogMessage
 \brief Classe permettant de gérer un message de Log (son contenu et son degre d'importance)
 */
class LogMessage {
private:
	/**<
	 Le contenu du message
	 */
    QString _message;
	/**<
	 Le degre d'importance du message
	 */
    int _degre;
    /**<
      La date du message
      */
    QString _date;
public:
	/*!
      \brief Crée un LogMessage avec des valeurs par défauts
      */
    LogMessage();
    /*!
      \brief Crée un LogMessage avec les paramètres de la méthode
      \param mes string
      \param degre int
      */
    LogMessage(const QString& mes, int degre) : _message(mes), _degre(degre) {
        // On détermine le temps actuel
		time_t temps_act;
        time(&temps_act);
        _date = ctime(&temps_act);
    }
    /*!
      \brief Getter du contenu du message
      \return le contenu du message
      */
    QString getMessage() const { return _message; }
    /*!
      \brief Getter de l'importance du message
      \return l'importance du message
      */
    int getDegre() const { return _degre; }
    /*!
      \brief Getter de la date du message
      \return la date du message
      */
    QString getDate() const { return _date; }
};


#endif // LOGMESSAGE_H
