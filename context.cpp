#include "context.h"

Context* Context::_instance = 0;

Context::Context() {

}

Context* Context::getInstance() {
    if(!_instance)
        _instance = new Context();
    return _instance;
}

void Context::freeInstance() {
    if(!_instance)
        delete _instance;
}
