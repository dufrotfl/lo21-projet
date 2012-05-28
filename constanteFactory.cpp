#include "constanteFactory.h"

Constante* ConstanteFactory::getConstante(const QString &str) {
    Constante *c;

    /* Teste si la chaine correspond � l'expression r�guli�re ^'.+'$
       c�d si c'est une suite de caract�res entre simples quotes.
       Dans ce cas, on renvoie un objet de type Expression. */
    if(str.indexOf(QRegExp("^'.+'$"))!=-1)
        c = new Expression(str);
    /* Sinon, teste si la chaine correspond � l'expression r�guli�re ^\d+$
       c�d si c'est une suite de chiffres.
       Dans ce cas, on renvoie un objet de type Entier. */
    else if(str.indexOf(QRegExp("^-?\d+$"))!=-1)
        c = new Entier(str.toInt());
    /* Sinon, teste si la chaine correspond � l'expression r�guli�re ^\d+\.\d+$
       ou ^\d+,\d+$ c�d si c'est deux suites de chiffres s�par�es pas un point
       ou une virgule.
       Dans ce cas, on renvoie un objet de type Reel. */
    else if(str.indexOf(QRegExp("^-?\d+\.\d+$"))!=-1 || str.indexOf(QRegExp("^\d+,\d+$"))!=-1)
        c = new Reel(str.toFloat());
    /* Sinon, teste si la chaine correspond � l'expression r�guli�re ^\d+/\d+$
       c�d si c'est deux suites de chiffres s�par�es pas un slash.
       Dans ce cas, on renvoie un objet de type Rationnel. */
    else if(str.indexOf(QRegExp("^\d+/-?\d+$"))!=-1) {
        // On r�cup�re la position du slash de s�paration
        int slashPos = str.indexOf("/");
        /* On d�coupe la chaine en deux pour cr�er un Rationnel.
           Le num�rateur est entre str[0] et str[slashPos-1]
           Le d�nominateur est entre str[slashPos+1] et str[str.length()] */
        c = new Rationnel(str.left(slashPos).toInt(), str.right(str.length()-slashPos).toInt());
    }
    /* Sinon, teste si la chaine correspond � l'expression r�guli�re ^\d+$\d+$
       c�d si c'est deux suites de chiffres s�par�es pas un dollar.
       Dans ce cas, on renvoie un objet de type NombreComplexe. */
    else if(str.indexOf(QRegExp("^\d+$\d+$"))!=-1) {
        /* Si l'utilisateur entre un complexe alors que le mode
           complexe n'est pas s�lectionn�, alors on envoie une
           ConstanteFactoryException qui sera transmise � la
           GUI qui s'occupera d'ajouter l'erreur au LogSystem si besoin. */
        if(Settings::getInstance()->getUtilisationDeComplexe()==NON_COMPLEXE) {
            delete c;
            throw ConstanteFactoryException("Mode complexe non selectionne", 1);
        }
        // On r�cup�re la position du dollar de s�paration
        int dollarPos = str.indexOf("$");
        Constante* reel = getConstante(str.left(dollarPos));
        NombreNonComplexe* nc = dynamic_cast<NombreNonComplexe*>(reel);
        Constante* imaginaire = getConstante(str.right(str.length()-dollarPos));
        NombreNonComplexe* nc2 = dynamic_cast<NombreNonComplexe*>(imaginaire);
        c = new NombreComplexe(nc, nc2);
    }
    /* Si la chaine ne correspond � aucune des expressions r�guli�res,
       alors on envoie une ConstanteFactoryException qui sera transmise � la
       GUI qui s'occupera d'ajouter l'erreur au LogSystem si besoin. */
    else {
        delete c;
        throw ConstanteFactoryException("Type non reconnu", 1);
    }

    return c;
}
