#include "constanteFactory.h"
#include "qdebug.h"

Constante* ConstanteFactory::getConstante(const QString &str) {
    QString strcopy(str.toUpper());
    /* Teste si la chaine correspond à l'expression régulière ^'.+'$
       càd si c'est une suite de caractères entre simples quotes.
       Dans ce cas, on renvoie un objet de type Expression. */
    if((QRegExp("^'\.+'$").indexIn(strcopy))!=-1) {
        return new Expression(strcopy);
    }
    /* Sinon, teste si la chaine correspond à l'expression régulière ^\d+$
       càd si c'est une suite de chiffres.
       Dans ce cas, on renvoie un objet de type Entier. */
    else if((QRegExp("^-?\\d+$").indexIn(strcopy))!=-1) {
        return new Entier(strcopy.toInt());
    }
    /* Sinon, teste si la chaine correspond à l'expression régulière ^\d+\.\d+$
       ou ^\d+,\d+$ càd si c'est deux suites de chiffres séparées pas un point
       ou une virgule.
       Dans ce cas, on renvoie un objet de type Reel. */
    else if((QRegExp("^-?\\d+\,\\d+$").indexIn(strcopy))!=-1 || (QRegExp("^-?\\d+\\.\\d+$").indexIn(strcopy))!=-1) {
        return new Reel(strcopy.toFloat());
    }
    /* Sinon, teste si la chaine correspond à l'expression régulière ^\d+/\d+$
       càd si c'est deux suites de chiffres séparées pas un slash.
       Dans ce cas, on renvoie un objet de type Rationnel. */
    else if((QRegExp("^-?\\d+/\\d+$").indexIn(strcopy))!=-1) {
        // On récupère la position du slash de séparation
        int slashPos = strcopy.indexOf("/");
        /* On découpe la chaine en deux pour créer un Rationnel.
           Le numérateur est entre str[0] et str[slashPos-1]
           Le dénominateur est entre str[slashPos+1] et str[str.length()] */
        return new Rationnel(strcopy.left(slashPos).toInt(), strcopy.right(strcopy.length()-slashPos-1).toInt());
    }
    /* Sinon, teste si la chaine correspond à l'expression régulière ^\d+$\d+$
       càd si c'est deux suites de chiffres séparées pas un dollar.
       Dans ce cas, on renvoie un objet de type NombreComplexe. */
    else if((QRegExp("^.+\\$.+$").indexIn(strcopy))!=-1) {
        /* Si l'utilisateur entre un complexe alors que le mode
           complexe n'est pas sélectionné, alors on envoie une
           ConstanteFactoryException qui sera transmise à la
           GUI qui s'occupera d'ajouter l'erreur au LogSystem si besoin. */
        if(Settings::getInstance()->getUtilisationDeComplexe()==Settings::NON_COMPLEXE) {
            throw LogMessage("Mode complexe non sélectionné", 1);
        }
        // On récupère la position du dollar de séparation
        int dollarPos = strcopy.indexOf("$");
        Constante* reel = ConstanteFactory::getConstante(strcopy.left(dollarPos));
        NombreNonComplexe* nc = dynamic_cast<NombreNonComplexe*>(reel);
        Constante* imaginaire = ConstanteFactory::getConstante(strcopy.right(strcopy.size()-dollarPos-1));

        NombreNonComplexe* nc2 = dynamic_cast<NombreNonComplexe*>(imaginaire);
        return new NombreComplexe(nc, nc2);
    }
    else if(strcopy=="+" || strcopy=="-" || strcopy=="/" || strcopy=="*" || strcopy=="POW" || strcopy=="MOD")
        return new Operateur(strcopy, 2);
    else if(strcopy=="SIN" || strcopy=="COS" || strcopy=="TAN" || strcopy=="SINH" || strcopy=="COSH" || strcopy=="TANH" || strcopy=="LN" || strcopy=="LOG" || strcopy=="INV" || strcopy=="SQRT" || strcopy=="SQR" || strcopy=="CUBE" || strcopy=="!" || strcopy=="EVAL")
        return new Operateur(strcopy, 1);
    else if(strcopy=="SWAP" || strcopy=="SUM" || strcopy=="MEAN" || strcopy=="CLEAR" || strcopy=="DUP" || strcopy=="DROP")
        return new Operateur(strcopy, 0);
    /* Si la chaine ne correspond à aucune des expressions régulières,
       alors on envoie une ConstanteFactoryException qui sera transmise à la
       GUI qui s'occupera d'ajouter l'erreur au LogSystem si besoin. */
    else {
        throw LogMessage("Type non reconnu", 1);
    }
}
