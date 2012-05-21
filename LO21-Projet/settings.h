/**
 * \file Settings.h
 * \brief Classe permettant de g�rer les param�tres de la calculatrice
 * \author Sebastien Fradcourt
 * \date 21 Mai 2012
 * \version 1.0
 */
 
#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

/*!
 * \enum UtilisationDeComplexe 
 * \brief Le r�glage concernant l'utilisation de complexe.
 */
enum UtilisationDeComplexe {
	/**< L'utilisation des complexes est autoris�e.*/
	OUI,
	/**< L'utilisation des complexes n'est pas autoris�e.*/
	NON
};

/*!
 * \enum Angles
 * \brief Le r�glage concernant l'unit� des angles.
 */
enum Angles {
	/**< Les angles sont exprim�s en degr�s.*/
	DEGRE,
	/**< Les angles sont exprim�es en radians.*/
	RADIAN
};

/*!
 * \enum TypeConstante
 * \brief Le r�glage concernant le type de constante en cours d'utilisation.
 */
enum TypeConstante {
	/**< Les constantes utilis�es sont de type entier.*/
	ENTIER,
	/**< Les constantes utilis�es sont de type rationnel.*/
	RATIONNEL,
	/**< Les constantes utilis�es sont de type r�el.*/
	REEL
};

/*! \class Settings
 *	\brief Classe permettant de g�rer les param�tres de la page (utilis�e dans le cadre de la sauvegarde de contexte notamment)	
 */
class Settings {
	private :
		/*!
		 * R�glage de l'utilisation des complexes
		 */
		UtilisationDeComplexe _utilisationDeComplexe;
		/*!
		 * R�glages concernant l'unit� des angles
		 */
		Angles _angles;
		/*!
		 * R�glages concernant le type de constante utilis�e
		 */
		TypeConstante _typeConstante;
	
	public :
		//! Constructeur sans parametre
		Settings();
		/*! Constructeur
		 * \param comp UtilisationDeComplexe
		 * \param an Angles
		 * \param co TypeConstante
		 */
		Settings(UtilisationDeComplexe comp, Angles an, TypeConstante co) : _utilisationDeComplexe(comp), _angles(an), _typeConstante(co) {}
		
		/**
		 * \brief getter du r�glage concernant l'utilisation des complexes
		 * \return _utilisationDeComplexe
		 */
		UtilisationDeComplexe getUtilisationDeComplexe() const {
			return _utilisationDeComplexe;
		}
		
		/**
		 * \brief setter du r�glage concernant l'utilisation des complexes
		 * \param comp UtilisationDeComplexe
		 */
		void setUtilisationDeComplexe(UtilisationDeComplexe comp) {
			_utilisationDeComplexe = comp;
		}
		
		/**
		 * \brief getter du r�glage concernant l'unit� des angles
		 * \return _angles
		 */
		Angles getAngles() const {
			return _angles;
		}
		
		/**
		 * \brief setter du r�glage concernant l'unit� des angles
		 * \param an Angles
		 */
		void setAngles(Angles an) {
			_angles = an;
		}
		
		/**
		 * \brief getter du r�glage concernant le type des constantes
		 * \return _typeConstante
		 */
		TypeConstante getTypeConstante() {
			return _typeConstante;
		}
		
		/**
		 * \brief setter du r�glage concernant le type des constantes
		 * \param co TypeConstante
		 */
		void setTypeConstante(TypeConstante co) {
			_typeConstante = co;
		}		
}

#endif