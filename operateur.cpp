#include "operateur.h"
#include "mainwindow.h"
#include "rationnel.h"
#include "reel.h"
#include "entier.h"
#include "nombreComplexe.h"
#include "nombreNonComplexe.h"
#include "qdebug.h"
#include "historiqueOperateurBinaire.h"
#include "historiqueOperateurSwap.h"
#include "historiqueOperateurUnaire.h"

Operateur* Operateur::clone() const {
    return new Operateur(getOperateur(), getArite());
}

Constante* Operateur::call(Constante* c1, Constante *c2) {
    // Si c'est un opérateur binaire
    if(_arite == 2) {
        // On test si les deux constantes sont des entiers
        if(typeid(*c1)==typeid(Entier) && typeid(*c2)==typeid(Entier)) {
            Entier* c1copy = dynamic_cast<Entier*>(c1);
            Entier* c2copy = dynamic_cast<Entier*>(c2);
            // Si l'opérateur est swap, alors on crée l'historique associé et on effectue le swap
            if(_operateur == "SWAP") {
                HistoriqueOperateurSwap *h = new HistoriqueOperateurSwap(c1copy, c2copy);
                MainWindow::getInstance()->getPile()->ajouteHistorique(h);
                MainWindow::getInstance()->getPile()->swap(c1copy->getVal(), c2copy->getVal());
                return NULL;
            }
            // Si c'est le modulo alors on crée l'historique associé et on ajoute le résultat sur le pile
            else if(_operateur == "MOD") {
                HistoriqueOperateurBinaire *h = new HistoriqueOperateurBinaire(c1copy, c2copy);
                MainWindow::getInstance()->getPile()->ajouteHistorique(h);
                Entier* r = new Entier(*c2copy);
                c1copy->mod(r->getVal());
                delete r;
                return h->setResultat(c1copy);
            }
        }
        // Ici on a un simple if ou lieu d'un elseif, car dans le cas ou les deux constantes sont des entiers mais que l'opérateur ne faisait pas parti de SWAP ou MOD,
        // on veut qu'il passe passe par ce if qui gère le POW globalement
        // On test cette fois-ci si la première opérande est un entier et la deuxième est un NombreNonComplexe
        if(typeid(*c2)==typeid(Entier) && (typeid(*c1)==typeid(Entier) || typeid(*c1)==typeid(Rationnel)) || typeid(*c1)==typeid(Reel)) {
            // Si l'opérateur est POW, alors on test le type de la deuxième opérande afin de gérer le cast, on crée l'historique associé et on stocke le résultat
            if(_operateur == "POW") {
                Entier* c2copy = dynamic_cast<Entier*>(c2);
                HistoriqueOperateurBinaire* h = new HistoriqueOperateurBinaire(c1, c2copy);
                MainWindow::getInstance()->getPile()->ajouteHistorique(h);
                if(typeid(*c1)==typeid(Entier)) {
                    Entier* c1copy = dynamic_cast<Entier*>(c1);
                    c1copy->pow(c2copy);
                    return h->setResultat(c1copy);
                }
                else if(typeid(*c1)==typeid(Rationnel)) {
                    Rationnel* c1copy = dynamic_cast<Rationnel*>(c1);
                    c1copy->pow(c2copy);
                    return h->setResultat(c1copy);
                }
                else if(typeid(*c1)==typeid(Reel)) {
                    Reel* c1copy = dynamic_cast<Reel*>(c1);
                    c1copy->pow(c2copy);
                    return h->setResultat(c1copy);
                }
            }
        }
        // On rentre dans le cas ou soit l'un des deux est une expression
        if(typeid(*c1)==typeid(Expression) || typeid(*c2)==typeid(Expression)) {
            // Dans le cas ou c'est c1 l'expression, on cast c1 et on appelle l'opérateur sur c1 (qui a été casté afin d'appeler la bonne méthode)
            // on crée l'historique associé et on stocke le résultat
            if(typeid(*c1)==typeid(Expression)) {
                Expression* c1copy = dynamic_cast<Expression*>(c1);
                HistoriqueOperateurBinaire *h = new HistoriqueOperateurBinaire(c1copy, c2);
                MainWindow::getInstance()->getPile()->ajouteHistorique(h);
                if(_operateur == "+")
                    return h->setResultat(*c1copy+c2);
                else if(_operateur == "-")
                    return h->setResultat(*c1copy-c2);
                else if(_operateur == "*")
                    return h->setResultat(*c1copy*c2);
                else if(_operateur == "/")
                    return h->setResultat(*c1copy/c2);
            }
            // Dans le cas ou c'est c2 l'expression, on cast c2 et on appelle l'opérateur sur c2 (qui a été casté afin d'appeler la bonne méthode)
            // on crée l'historique associé et on stocke le résultat
            else if(typeid(*c2)==typeid(Expression)) {
                Expression* c2copy = dynamic_cast<Expression*>(c2);
                HistoriqueOperateurBinaire *h = new HistoriqueOperateurBinaire(c1, c2copy);
                MainWindow::getInstance()->getPile()->ajouteHistorique(h);
                if(_operateur == "+")
                    return h->setResultat(*c2copy+c1);
                else if(_operateur == "-")
                    return h->setResultat(*c2copy-c1);
                else if(_operateur == "*")
                    return h->setResultat(*c2copy*c1);
                else if(_operateur == "/")
                    return h->setResultat(*c2copy/c1);
            }
            // ! NOTE IMPORTANTE, dans le cas ou les deux sont expressions alors on passera dans le premier test (le cast de c1)
        }
        // Si les 2 constantes sont complexes, alors on test si l'opérateur est +-*/ afin d'appeler le bon, si l'opérateur ne fait pas parti de ceux-ci on sort du if
        else if(typeid(*c1)==typeid(NombreComplexe) && typeid(*c2)==typeid(NombreComplexe)) {
                NombreComplexe* c1copy = dynamic_cast<NombreComplexe*>(c1);
                NombreComplexe* c2copy = dynamic_cast<NombreComplexe*>(c2);
                HistoriqueOperateurBinaire *h = new HistoriqueOperateurBinaire(c1copy, c2copy);
                MainWindow::getInstance()->getPile()->ajouteHistorique(h);
                if(_operateur == "+")
                    return h->setResultat(*c1copy+c2copy);
                else if(_operateur == "-")
                    return h->setResultat(*c1copy-c2copy);
                else if(_operateur == "*")
                    return h->setResultat(*c1copy*c2copy);
                else if(_operateur == "/")
                    return h->setResultat(*c1copy/c2copy);
        }
        // Si la première constante est un entier, on test ensuite si l'opérateur fait parti de +-*/, si oui on crée l'historique associé et on stocke le résultat
        else if(typeid(*c1)==typeid(Entier)) {
            Entier* c1copy = dynamic_cast<Entier*>(c1);
            NombreNonComplexe* c2copy = dynamic_cast<NombreNonComplexe*>(c2);
            HistoriqueOperateurBinaire *h = new HistoriqueOperateurBinaire(c1copy, c2copy);
            MainWindow::getInstance()->getPile()->ajouteHistorique(h);
            if(_operateur == "+")
                return h->setResultat(*c1copy+c2copy);
            else if(_operateur == "-")
                return h->setResultat(*c1copy-c2copy);
            else if(_operateur == "*")
                return h->setResultat(*c1copy*c2copy);
            else if(_operateur == "/")
                return h->setResultat(*c1copy/c2copy);
        }
        // Si la première constante est un rationnel, on test ensuite si l'opérateur fait parti de +-*/, si oui on crée l'historique associé et on stocke le résultat
        else if(typeid(*c1)==typeid(Rationnel)) {
            Rationnel* c1copy = dynamic_cast<Rationnel*>(c1);
            NombreNonComplexe* c2copy = dynamic_cast<NombreNonComplexe*>(c2);
            HistoriqueOperateurBinaire *h = new HistoriqueOperateurBinaire(c1copy, c2copy);
            MainWindow::getInstance()->getPile()->ajouteHistorique(h);
            if(_operateur == "+")
                return h->setResultat(*c1copy+c2copy);
            else if(_operateur == "-")
                return h->setResultat(*c1copy-c2copy);
            else if(_operateur == "*")
                return h->setResultat(*c1copy*c2copy);
            else if(_operateur == "/")
                return h->setResultat(*c1copy/c2copy);
        }
        // Si la première constante est un réel, on test ensuite si l'opérateur fait parti de +-*/, si oui on crée l'historique associé et on stocke le résultat
        else if(typeid(*c1)==typeid(Reel)) {
            Reel* c1copy = dynamic_cast<Reel*>(c1);
            NombreNonComplexe* c2copy = dynamic_cast<NombreNonComplexe*>(c2);
            HistoriqueOperateurBinaire *h = new HistoriqueOperateurBinaire(c1copy, c2copy);
            MainWindow::getInstance()->getPile()->ajouteHistorique(h);
            if(_operateur == "+")
                return h->setResultat(*c1copy+c2copy);
            else if(_operateur == "-")
                return h->setResultat(*c1copy-c2copy);
            else if(_operateur == "*")
                return h->setResultat(*c1copy*c2copy);
            else if(_operateur == "/")
                return h->setResultat(*c1copy/c2copy);
        }
        // Dans le cas ou c'est un opérateur d'arité deux, mais que les constantes ne sont pas applicables alors on lance une exception de type LogMessage
        else
            throw LogMessage("Opérateur d'arité 2 non applicable sur ces constantes", 1);
    }
    // Si c'est un opérateur unaire
    else if(_arite == 1) {
        // Si c1 est un entier, on test ensuite si l'opérateur est "SUM" ou "MEAN" ou "!", si oui on crée l'historique associé et on stocke le résultat
        // ! Dans le cas de sum et de mean, l'historique est géré à l'intérieur de ces fonctions
        if(typeid(*c1)==typeid(Entier)) {
            Entier* nbr = dynamic_cast<Entier*>(c1);
            if(_operateur == "SUM") {
                MainWindow::getInstance()->getPile()->sum(nbr->getVal());
                return NULL;
            }
            else if(_operateur == "MEAN") {
                MainWindow::getInstance()->getPile()->mean(nbr->getVal());
                return NULL;
            }
            else if(_operateur == "!") {
                HistoriqueOperateurUnaire *h = new HistoriqueOperateurUnaire(nbr);
                MainWindow::getInstance()->getPile()->ajouteHistorique(h);
                nbr->fact();
                return h->setResultat(nbr);
            }
        }
        // Si c1 est un entier, rationnel, réel ou complexe
        if(typeid(*c1)==typeid(Entier) || typeid(*c1)==typeid(Rationnel) || typeid(*c1)==typeid(Reel) || typeid(*c1)==typeid(NombreComplexe)) {
            // On refait un test pour savoir si celui-ci fait parti de entier, rationnel ou reel, si c'est le cas...
            // Ensuite en fonction de l'opérateur on appelle celle-ci sur la constante, on crée l'historique associé et on stocke le résultat
            // ! Ici on cast en "Nombre" car les méthodes COS, SIN, etc on été définit dans la classe Nombre donc on peut généraliser
            Nombre * nbr = dynamic_cast<Nombre*>(c1);
            HistoriqueOperateurUnaire *h = new HistoriqueOperateurUnaire(nbr);
            MainWindow::getInstance()->getPile()->ajouteHistorique(h);
            if(_operateur == "COS")
                return h->setResultat(nbr->Acos());
            else if(_operateur == "SIN")
                return h->setResultat(nbr->Asin());
            else if(_operateur == "TAN")
                return h->setResultat(nbr->Atan());
            else if(_operateur == "COSH")
                return h->setResultat(nbr->Acosh());
            else if(_operateur == "SINH")
                return h->setResultat(nbr->Asinh());
            else if(_operateur == "TANH")
                return h->setResultat(nbr->Atanh());
            else if(_operateur == "LN")
                return h->setResultat(nbr->Aln());
            else if(_operateur == "LOG")
                return h->setResultat(nbr->Alog());
            else if(_operateur == "INV")
                return h->setResultat(nbr->Ainv());
            else if(_operateur == "SQRT")
                return h->setResultat(nbr->Asqrt());
            else if(_operateur == "CUBE"){
                nbr->cube();
                return h->setResultat(nbr);
            }
            else if(_operateur == "SQR"){
                nbr->sqr();
                return h->setResultat(nbr);
            }
            else if(_operateur == "SIGN") {
                nbr->sign();
                return h->setResultat(nbr);
            }
            // Dans le cas ou c'est un nombreComplexe, on lance une exception de type LogMessage afin de signalé que les opérateurs ici
            // ne sont pas applicables sur des nombres complexes
            else {
                MainWindow::getInstance()->getPile()->push(c1);
                throw LogMessage("L'opérateur n'est pas autorisé sur des nombres complexes", 1);
            }
        }
        // Si c'est une expression, alors on le cast, on crée l'historique associé et on stocke le résultat
        else if(typeid(*c1)==typeid(Expression)) {            
            HistoriqueOperateurUnaire *h = new HistoriqueOperateurUnaire(c1);
            MainWindow::getInstance()->getPile()->ajouteHistorique(h);
            Expression* e = dynamic_cast<Expression*>(c1);
            return h->setResultat(*e+this);
        }
        // Sinon c'est que la combinaison de la constante et de l'opérateur n'existe pas, et donc on renvoie une exception de type LogMessage
        else {
            MainWindow::getInstance()->getPile()->push(c1);
            throw LogMessage("Opérateur d'arité 1 non applicable ici.", 1);
        }
    }
    // Si c'est un opérateur d'arité 0 (ne prenant aucun argument, et qui se trouve être des opérations sur la pile
    else if(_arite == 0) {
        // Si l'opérateur est "DUP" alors on appelle celui-ci
        // ! Notons que l'historique est géré dans la fonction dup, celle-ci utilise le type HistoriqueOperateurPush
        if(_operateur == "DUP") {
            MainWindow::getInstance()->getPile()->dup();
            return NULL;
        }        
        // Si l'opérateur est "DROP" alors on appelle celui-ci
        if(_operateur == "DROP") {
            MainWindow::getInstance()->getPile()->drop();
            return NULL;
        }
    }
    // ! On ne met pas de else ici puisqu'un opérateur à un opérateur compris entre 0 et 2.
}
