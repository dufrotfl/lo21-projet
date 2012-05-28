#include "expression.h"

Nombre* Expression::eval() const throw(ConstanteException) {
    return new Entier();
}
