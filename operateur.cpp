#include "operateur.h"

#include "entier.h"
#include "nombreComplexe.h"
#include "nombreNonComplexe.h"
#include "qdebug.h"

Constante* Operateur::call(Constante* c1, Constante *c2) {
    if(c2) {
        // ON rentre dans le cas ou soit l'un des deux est une expression
        if(typeid(*c1)==typeid(Expression) || typeid(*c2)==typeid(Expression)) {
            if(typeid(*c1)==typeid(Expression)) {
                qDebug() << "call :)";
                Expression* c1copy = dynamic_cast<Expression*>(c1);
                qDebug() << "call :)";
                if(_operateur == "+")
                    return *c1copy+c2;
                if(_operateur == "-")
                    return *c1copy-c2;
                if(_operateur == "*")
                    return *c1copy*c2;
                if(_operateur == "/")
                    return *c1copy/c2;
            }
            else if(typeid(*c2)==typeid(Expression)) {
                Expression* c2copy = dynamic_cast<Expression*>(c2);
                if(_operateur == "+")
                    return *c2copy+c1;
                if(_operateur == "-")
                    return *c2copy-c1;
                if(_operateur == "*")
                    return *c2copy*c1;
                if(_operateur == "/")
                    return *c2copy/c1;
            }
        }
        // On rentre dans le cas ou  les deux sont complexes
        if(typeid(*c1)==typeid(NombreComplexe) && typeid(*c2)==typeid(NombreComplexe)) {
                NombreComplexe* c1copy = dynamic_cast<NombreComplexe*>(c1);
                NombreComplexe* c2copy = dynamic_cast<NombreComplexe*>(c2);
                if(_operateur == "+")
                    return *c1copy+c2copy;
                if(_operateur == "-")
                    return *c1copy-c2copy;
                if(_operateur == "*")
                    return *c1copy*c2copy;
                if(_operateur == "/")
                    return *c1copy/c2copy;
        }
        /*else if(typeid(*c1)==typeid(NombreNonComplexe) && typeid(*c2)==typeid(NombreNonComplexe)) {

        }

        }
        if(typeid(*c1)==typeid(NombreNonComplexe) && typeid(*c2)==typeid(NombreNonComplexe)) {
            c1 = dynamic_cast<NombreNonComplexe*>(c1);
            c2 = dynamic_cast<NombreNonComplexe*>(c2);
            return *c1+c2;
        }
        if(typeid(*c1)==typeid(Expression)) {
            c1 = dynamic_cast<Expression*>(c1);
            return *c1+c2;
        }
        if(typeid(*c2)==typeid(Expression)) {
            c2 = dynamic_cast<Expression*>(c2);
            return *c1+c2;
        }*/
        else
            throw LogMessage("Probleme au niveau du call", 1);
    }

}
