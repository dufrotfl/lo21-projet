#include "operateur.h"
#include "mainwindow.h"
#include "rationnel.h"
#include "reel.h"
#include "entier.h"
#include "nombreComplexe.h"
#include "nombreNonComplexe.h"
#include "qdebug.h"

Constante* Operateur::call(Constante* c1, Constante *c2) {
    if(_arite == 2) {
        if(typeid(*c1)==typeid(Entier) && typeid(*c2)==typeid(Entier)) {
            Entier* c1copy = dynamic_cast<Entier*>(c1);
            Entier* c2copy = dynamic_cast<Entier*>(c2);
            if(_operateur == "SWAP") {
                MainWindow::getInstance()->getPile()->swap(c1copy->getVal(), c2copy->getVal());
                return NULL;
            }
        }
        // ON rentre dans le cas ou soit l'un des deux est une expression
        if(typeid(*c1)==typeid(Expression) || typeid(*c2)==typeid(Expression)) {
            if(typeid(*c1)==typeid(Expression)) {
                Expression* c1copy = dynamic_cast<Expression*>(c1);
                if(_operateur == "+")
                    return *c1copy+c2;
                else if(_operateur == "-")
                    return *c1copy-c2;
                else if(_operateur == "*")
                    return *c1copy*c2;
                else if(_operateur == "/")
                    return *c1copy/c2;
            }
            else if(typeid(*c2)==typeid(Expression)) {
                Expression* c2copy = dynamic_cast<Expression*>(c2);
                if(_operateur == "+")
                    return *c2copy+c1;
                else if(_operateur == "-")
                    return *c2copy-c1;
                else if(_operateur == "*")
                    return *c2copy*c1;
                else if(_operateur == "/")
                    return *c2copy/c1;
            }
        }
        // On rentre dans le cas ou  les deux sont complexes
        else if(typeid(*c1)==typeid(NombreComplexe) && typeid(*c2)==typeid(NombreComplexe)) {
                NombreComplexe* c1copy = dynamic_cast<NombreComplexe*>(c1);
                NombreComplexe* c2copy = dynamic_cast<NombreComplexe*>(c2);
                if(_operateur == "+")
                    return *c1copy+c2copy;
                else if(_operateur == "-")
                    return *c1copy-c2copy;
                else if(_operateur == "*")
                    return *c1copy*c2copy;
                else if(_operateur == "/")
                    return *c1copy/c2copy;
        }
        else if(typeid(*c1)==typeid(Entier)) {
            Entier* c1copy = dynamic_cast<Entier*>(c1);
            NombreNonComplexe* c2copy = dynamic_cast<NombreNonComplexe*>(c2);
            if(_operateur == "+")
                return *c1copy+c2copy;
            else if(_operateur == "-")
                return *c1copy-c2copy;
            else if(_operateur == "*")
                return *c1copy*c2copy;
            else if(_operateur == "/") {
                qDebug() << "yo";
                return *c1copy/c2copy;
            }
        }
        else if(typeid(*c1)==typeid(Rationnel)) {
            Rationnel* c1copy = dynamic_cast<Rationnel*>(c1);
            NombreNonComplexe* c2copy = dynamic_cast<NombreNonComplexe*>(c2);
            if(_operateur == "+")
                return *c1copy+c2copy;
            else if(_operateur == "-")
                return *c1copy-c2copy;
            else if(_operateur == "*")
                return *c1copy*c2copy;
            else if(_operateur == "/")
                return *c1copy/c2copy;
        }
        else if(typeid(*c1)==typeid(Reel)) {
            Reel* c1copy = dynamic_cast<Reel*>(c1);
            NombreNonComplexe* c2copy = dynamic_cast<NombreNonComplexe*>(c2);
            if(_operateur == "+")
                return *c1copy+c2copy;
            else if(_operateur == "-")
                return *c1copy-c2copy;
            else if(_operateur == "*")
                return *c1copy*c2copy;
            else if(_operateur == "/")
                return *c1copy/c2copy;
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
            if(_operateur == "MEAN") {
                MainWindow::getInstance()->getPile()->mean(nbr->getVal());
                return NULL;
            }
        }
        if(typeid(*c1)==typeid(Entier) || typeid(*c1)==typeid(Rationnel) || typeid(*c1)==typeid(Reel) || typeid(*c1)==typeid(NombreComplexe)) {
            if(typeid(*c1)==typeid(Entier) || typeid(*c1)==typeid(Rationnel) || typeid(*c1)==typeid(Reel)) {
                Nombre * nbr = dynamic_cast<Nombre*>(c1);
                if(_operateur == "COS")
                    return nbr->Acos();
                else if(_operateur == "SIN")
                    return nbr->Asin();
                else if(_operateur == "TAN")
                    return nbr->Atan();
                else if(_operateur == "COSH")
                    return nbr->Acosh();
                else if(_operateur == "SINH")
                    return nbr->Asinh();
                else if(_operateur == "TANH")
                    return nbr->Atanh();
                else if(_operateur == "LN")
                    return nbr->Aln();
                else if(_operateur == "LOG")
                    return nbr->Alog();
                else if(_operateur == "INV")
                    return nbr->Ainv();
                else if(_operateur == "SQRT")
                    return nbr->Asqrt();
            }
        }
        else
            throw LogMessage("Opérateur d'arité 1 non reconnu.", 1);
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
