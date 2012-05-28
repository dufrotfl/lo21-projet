/*!
 \file settings.h
 \brief Classe permettant de gerer les paramètres de la calculatrice
 \author Sebastien Fradcourt & Florian Dufrot
 \date 21 Mai 2012
 \version 1.0
 */
 
#ifndef SETTINGS_H
#define SETTINGS_H

/*!
 \enum UtilisationDeComplexe
 \brief Le reglage concernant l'utilisation de complexe.
 */
enum UtilisationDeComplexe {
    /*! L'utilisation des complexes est autorisee.*/
    COMPLEXE,
    /*! L'utilisation des complexes n'est pas autorisee.*/
    NON_COMPLEXE
};

/*!
 \enum Angles
 \brief Le reglage concernant l'unite des angles.
 */
enum Angles {
    /*! Les angles sont exprimes en degres.*/
    DEGRES,
    /*! Les angles sont exprimees en radians.*/
    RADIANS
};

/*!
 \enum TypeConstante
 \brief Le reglage concernant le type de constante en cours d'utilisation.
 */
enum TypeConstante {
    /*! Les constantes utilisees sont de type entier.*/
    ENTIER,
    /*! Les constantes utilisees sont de type rationnel.*/
    RATIONNEL,
    /*! Les constantes utilisees sont de type reel.*/
    REEL
};


/*!
 \class Settings
 \brief Classe permettant de gerer les paramètres de la page (utilisee dans le cadre de la sauvegarde de contexte notamment)
 */
class Settings {
	private :
		/*!
         Reglage de l'utilisation des complexes
		 */
        UtilisationDeComplexe _utilisationDeComplexe;
		/*!
         Reglages concernant l'unite des angles
		 */
        Angles _angles;
		/*!
         Reglages concernant le type de constante utilisee
		 */
        TypeConstante _typeConstante;

        static Settings* _instance;

        //! Constructeur sans parametre
        Settings();

        Settings(UtilisationDeComplexe, Angles, TypeConstante);
	
	public :

        static Settings* getInstance();

        static void freeInstance();


		
		/**
         \brief getter du reglage concernant l'utilisation des complexes
         \return _utilisationDeComplexe
		 */
        UtilisationDeComplexe getUtilisationDeComplexe() {
			return _utilisationDeComplexe;
		}
		
		/**
         \brief setter du reglage concernant l'utilisation des complexes
         \param comp UtilisationDeComplexe
		 */
		void setUtilisationDeComplexe(UtilisationDeComplexe comp) {
			_utilisationDeComplexe = comp;
		}
		
		/**
         \brief getter du reglage concernant l'unite des angles
         \return _angles
		 */
        Angles getAngles() {
			return _angles;
		}
		
		/**
         \brief setter du reglage concernant l'unite des angles
         \param an Angles
		 */
		void setAngles(Angles an) {
			_angles = an;
		}
		
		/**
         \brief getter du reglage concernant le type des constantes
         \return _typeConstante
		 */
        TypeConstante getTypeConstante() {
			return _typeConstante;
		}
		
		/**
         \brief setter du reglage concernant le type des constantes
         \param co TypeConstante
		 */
		void setTypeConstante(TypeConstante co) {
			_typeConstante = co;
		}		
};

#endif
