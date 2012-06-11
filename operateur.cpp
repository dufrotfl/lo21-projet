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
    if(_arite == 2) {
        if(typeid(*c1)==typeid(Entier) && typeid(*c2)==typeid(Entier)) {
            Entier* c1copy = dynamic_cast<Entier*>(c1);
            Entier* c2copy = dynamic_cast<Entier*>(c2);
            if(_operateur == "SWAP") {
                HistoriqueOperateurSwap *h = new HistoriqueOperateurSwap(c1copy, c2copy);
                MainWindow::getInstance()->getPile()->ajouteHistorique(h);
                MainWindow::getInstance()->getPile()->swap(c1copy->getVal(), c2copy->getVal());
                return NULL;
            }
            else if(_operateur == "MOD") {
                HistoriqueOperateurBinaire *h = new HistoriqueOperateurBinaire(c1copy, c2copy);
                MainWindow::getInstance()->getPile()->ajouteHistorique(h);
                qDebug() << "coucou";
                Entier* r = new Entier(*c2copy);
                c1copy->mod(r->getVal());
                return h->setResultat(c1copy);
            }
        }
        if(typeid(*c2)==typeid(Entier) && (typeid(*c1)==typeid(Entier) || typeid(*c1)==typeid(Rationnel)) || typeid(*c1)==typeid(Reel)) {
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
        // ON rentre dans le cas ou soit l'un des deux est une expression
        if(typeid(*c1)==typeid(Expression) || typeid(*c2)==typeid(Expression)) {
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
        }
        // On rentre dans le cas ou  les deux sont complexes
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
        else
            throw LogMessage("Opérateur d'arité 2 non reconnu", 1);
    }
    else if(_arite == 1) {
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
        if(typeid(*c1)==typeid(Entier) || typeid(*c1)==typeid(Rationnel) || typeid(*c1)==typeid(Reel) || typeid(*c1)==typeid(NombreComplexe)) {
            if(typeid(*c1)==typeid(Entier) || typeid(*c1)==typeid(Rationnel) || typeid(*c1)==typeid(Reel)) {
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
            }
            else {
                MainWindow::getInstance()->getPile()->push(c1);
                throw LogMessage("L'opérateur n'est pas autorisé sur des nombres complexes", 1);
            }
        }
        else if(typeid(*c1)==typeid(Expression)) {            
            HistoriqueOperateurUnaire *h = new HistoriqueOperateurUnaire(c1);
            MainWindow::getInstance()->getPile()->ajouteHistorique(h);
            Expression* e = dynamic_cast<Expression*>(c1);
            return h->setResultat(*e+this);
        }
        else {
            MainWindow::getInstance()->getPile()->push(c1);
            throw LogMessage("Opérateur d'arité 1 non reconnu.", 1);
        }
    }
    else if(_arite == 0) {
        if(_operateur == "DUP") {
            MainWindow::getInstance()->getPile()->dup();
            return NULL;
        }
        if(_operateur == "DROP") {
            MainWindow::getInstance()->getPile()->drop();
            return NULL;
        }
    }
}
