#include "constanteFactory.h"

Constante* ConstanteFactory::getConstante(const QString &str) {
    Constante *c;

    /* Teste si la chaine correspond à l'expression régulière ^'.+'$
       càd si c'est une suite de caractères entre simples quotes.
       Dans ce cas, on renvoie un objet de type Expression. */
    if(str.indexOf(QRegExp("^'.+'$"))!=-1)
        c = new Expression(str);
    /* Sinon, teste si la chaine correspond à l'expression régulière ^\d+$
       càd si c'est une suite de chiffres.
       Dans ce cas, on renvoie un objet de type Entier. */
    else if(str.indexOf(QRegExp("^-?\d+$"))!=-1)
        c = new Entier(str.toInt());
    /* Sinon, teste si la chaine correspond à l'expression régulière ^\d+\.\d+$
       ou ^\d+,\d+$ càd si c'est deux suites de chiffres séparées pas un point
       ou une virgule.
       Dans ce cas, on renvoie un objet de type Reel. */
    else if(str.indexOf(QRegExp("^-?\d+\.\d+$"))!=-1 || str.indexOf(QRegExp("^\d+,\d+$"))!=-1)
        c = new Reel(str.toFloat());
    /* Sinon, teste si la chaine correspond à l'expression régulière ^\d+/\d+$
       càd si c'est deux suites de chiffres séparées pas un slash.
       Dans ce cas, on renvoie un objet de type Rationnel. */
    else if(str.indexOf(QRegExp("^\d+/-?\d+$"))!=-1) {
        // On récupère la position du slash de séparation
        int slashPos = str.indexOf("/");
        /* On découpe la chaine en deux pour créer un Rationnel.
           Le numérateur est entre str[0] et str[slashPos-1]
           Le dénominateur est entre str[slashPos+1] et str[str.length()] */
        c = new Rationnel(str.left(slashPos).toInt(), str.right(str.length()-slashPos).toInt());
    }
    /* Sinon, teste si la chaine correspond à l'expression régulière ^\d+$\d+$
       càd si c'est deux suites de chiffres séparées pas un dollar.
       Dans ce cas, on renvoie un objet de type NombreComplexe. */
    else if(str.indexOf(QRegExp("^\d+$\d+$"))!=-1) {
        /* Si l'utilisateur entre un complexe alors que le mode
           complexe n'est pas sélectionné, alors on envoie une
           ConstanteFactoryException qui sera transmise à la
           GUI qui s'occupera d'ajouter l'erreur au LogSystem si besoin. */
        if(Settings::getInstance()->getUtilisationDeComplexe()==NON_COMPLEXE) {
            delete c;
            throw ConstanteFactoryException("Mode complexe non selectionne", 1);
        }
        // On récupère la position du dollar de séparation
        int dollarPos = str.indexOf("$");
        Constante* reel = getConstante(str.left(dollarPos));
        NombreNonComplexe* nc = dynamic_cast<NombreNonComplexe*>(reel);
        Constante* imaginaire = getConstante(str.right(str.length()-dollarPos));
        NombreNonComplexe* nc2 = dynamic_cast<NombreNonComplexe*>(imaginaire);
        c = new NombreComplexe(nc, nc2);
    }
    /* Si la chaine ne correspond à aucune des expressions régulières,
       alors on envoie une ConstanteFactoryException qui sera transmise à la
       GUI qui s'occupera d'ajouter l'erreur au LogSystem si besoin. */
    else {
        delete c;
        throw ConstanteFactoryException("Type non reconnu", 1);
    }

    return c;
}
