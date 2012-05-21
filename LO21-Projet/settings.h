/**
 * \file Settings.h
 * \brief Classe permettant de gérer les paramètres de la calculatrice
 * \author Sebastien Fradcourt
 * \date 21 Mai 2012
 * \version 1.0
 */
 
#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

/*!
 * \enum UtilisationDeComplexe 
 * \brief Le réglage concernant l'utilisation de complexe.
 */
enum UtilisationDeComplexe {
	/**< L'utilisation des complexes est autorisée.*/
	OUI,
	/**< L'utilisation des complexes n'est pas autorisée.*/
	NON
};

/*!
 * \enum Angles
 * \brief Le réglage concernant l'unité des angles.
 */
enum Angles {
	/**< Les angles sont exprimés en degrés.*/
	DEGRE,
	/**< Les angles sont exprimées en radians.*/
	RADIAN
};

/*!
 * \enum TypeConstante
 * \brief Le réglage concernant le type de constante en cours d'utilisation.
 */
enum TypeConstante {
	/**< Les constantes utilisées sont de type entier.*/
	ENTIER,
	/**< Les constantes utilisées sont de type rationnel.*/
	RATIONNEL,
	/**< Les constantes utilisées sont de type réel.*/
	REEL
};

/*! \class Settings
 *	\brief Classe permettant de gérer les paramètres de la page (utilisée dans le cadre de la sauvegarde de contexte notamment)	
 */
class Settings {
	private :
		/*!
		 * Réglage de l'utilisation des complexes
		 */
		UtilisationDeComplexe _utilisationDeComplexe;
		/*!
		 * Réglages concernant l'unité des angles
		 */
		Angles _angles;
		/*!
		 * Réglages concernant le type de constante utilisée
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
		 * \brief getter du réglage concernant l'utilisation des complexes
		 * \return _utilisationDeComplexe
		 */
		UtilisationDeComplexe getUtilisationDeComplexe() const {
			return _utilisationDeComplexe;
		}
		
		/**
		 * \brief setter du réglage concernant l'utilisation des complexes
		 * \param comp UtilisationDeComplexe
		 */
		void setUtilisationDeComplexe(UtilisationDeComplexe comp) {
			_utilisationDeComplexe = comp;
		}
		
		/**
		 * \brief getter du réglage concernant l'unité des angles
		 * \return _angles
		 */
		Angles getAngles() const {
			return _angles;
		}
		
		/**
		 * \brief setter du réglage concernant l'unité des angles
		 * \param an Angles
		 */
		void setAngles(Angles an) {
			_angles = an;
		}
		
		/**
		 * \brief getter du réglage concernant le type des constantes
		 * \return _typeConstante
		 */
		TypeConstante getTypeConstante() {
			return _typeConstante;
		}
		
		/**
		 * \brief setter du réglage concernant le type des constantes
		 * \param co TypeConstante
		 */
		void setTypeConstante(TypeConstante co) {
			_typeConstante = co;
		}		
}

#endif