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
 \class Settings
 \brief Classe permettant de gerer les paramètres de la calculatrice (utilisee dans le cadre de la sauvegarde de contexte notamment)
 */
class Settings {
    public:
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
        /*!
          Reglages du nombre de valeur de la pile à afficher
          */
        int _nbElemAffichable;
        /**<
          Instance de la classe Settings
          */
        static Settings* _instance;
        /*!
         \brief Constructeur sans parametre
         */
        Settings();
        /*!
          \brief Constructeur avec parametres
          \param comp L'utilisation des complexes
          \param an L'unité des angles
          \param cons Le type de constante
          \param nbElem Le nombre d'élément de la pile à afficher dans l'interface
          */
        Settings(UtilisationDeComplexe comp, Angles an, TypeConstante cons,int nbElem);
	
    public :
        /*!
          \brief Méthode permettant de retourner l'instance de la classe Settings
          \return L'instance
          */
        static Settings* getInstance();
        /*!
          \brief Méthode permettant de libérer l'instance
          */
        static void freeInstance();		
		/**
         \brief getter du reglage concernant l'utilisation des complexes
         \return L'utilisation ou non des complexes
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
         \return L'unité d'angles utilisée
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
         \return Le type de constante utilisé
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
        /**
         \brief getter du reglage concernant le nombre d'elements de la pile affichable
         \return Le nombre d'éléments de la pile à afficher
         */
        int getNbElemAffichable() {
            return _nbElemAffichable;
        }
        /**
         \brief setter du reglage concernant le nombre d'éléments à afficher dans la pile
         \param nbElement Nombre d'éléments de la pile à afficher
         */
        void setNbElementAffichable(int nbElement);
};

#endif
