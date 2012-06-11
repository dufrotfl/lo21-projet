#include "context.h"
#include "qsettings.h"
#include "qdebug.h"
#include "QtXml/QDomDocument"


Context* Context::_instance = 0;

Context::Context() {}

Context* Context::getInstance() {
    if(!_instance)
        _instance = new Context();
    return _instance;
}

void Context::freeInstance() {
    if(!_instance)
        delete _instance;
}

void Context::sauvegardeContext() {
    Settings* set = Settings::getInstance();
    Pile* p = MainWindow::getInstance()->getPile();

    // Essai avec QXml
    QDomDocument doc("context");
    QDomElement root = doc.createElement("Contexte");
    doc.appendChild(root);

    QDomElement elem1 = doc.createElement("Angles");
    if(set->getAngles() == Settings::RADIANS) {
        QDomText elem1t = doc.createTextNode("RADIANS");
        elem1.appendChild(elem1t);
    }
    else if(set->getAngles() == Settings::DEGRES) {
        QDomText elem1t = doc.createTextNode("DEGRES");
        elem1.appendChild(elem1t);
    }
    QDomElement elem3 = doc.createElement("Complexe");
    if(set->getUtilisationDeComplexe() == Settings::NON_COMPLEXE) {
        QDomText elem3t = doc.createTextNode("NON_COMPLEXE");
        elem3.appendChild(elem3t);
    }
    else if(set->getUtilisationDeComplexe() == Settings::COMPLEXE) {
        QDomText elem3t = doc.createTextNode("COMPLEXE");
        elem3.appendChild(elem3t);
    }
    QDomElement elem2 = doc.createElement("TypeConstante");
    if(set->getTypeConstante() == Settings::ENTIER) {
        QDomText elem2t = doc.createTextNode("ENTIER");
        elem2.appendChild(elem2t);
    }
    else if(set->getTypeConstante() == Settings::RATIONNEL) {
        QDomText elem2t = doc.createTextNode("RATIONNEL");
        elem2.appendChild(elem2t);
    }
    else if(set->getTypeConstante() == Settings::REEL) {
        QDomText elem2t = doc.createTextNode("REEL");
        elem2.appendChild(elem2t);
    }
    QDomElement elem4 = doc.createElement("NbElementAffichable");
    QDomText elem4t = doc.createTextNode(QString::number(set->getNbElemAffichable()));
    elem4.appendChild(elem4t);
    QDomElement elem5 = doc.createElement("ContenuPile");
    QDomText elem5t = doc.createTextNode(p->getPileString());
    elem5.appendChild(elem5t);
    root.appendChild(elem1);
    root.appendChild(elem2);
    root.appendChild(elem3);
    root.appendChild(elem4);
    root.appendChild(elem5);
    QString xml = doc.toString();

    QFile file("contexte.xml");

    if(!file.open(QIODevice::ReadWrite))
        return;
    file.resize(0);
    QTextStream ts( &file );
    ts << doc.toString();
    file.close();
}

void Context::chargerContext() {    
    Settings* set = Settings::getInstance();
    QFile file("contexte.xml");
    if(!file.open(QIODevice::ReadOnly)) {
        throw LogMessage("Problème du chargement du contexte !", 1);
    }
    QDomDocument doc("Contexte");
    if (!doc.setContent(&file)) {
         file.close();
         return;
     }
     file.close();

     QDomElement docElem = doc.documentElement();

     QDomNode n = docElem.firstChild();
     while(!n.isNull()) {
         QDomElement e = n.toElement(); // try to convert the node to an element.
         if(!e.isNull()) {
             if(e.nodeName() == "Angles") {
                 if(e.text() == "RADIANS") {
                     set->setAngles(Settings::RADIANS);
                 }
                 else if(e.text() == "DEGRES")
                     set->setAngles(Settings::DEGRES);
                 else
                     throw LogMessage("Erreur lors du chargement du contexte", 2);
             }
             else if(e.nodeName() == "TypeConstante") {
                 if(e.text() == "ENTIER") {
                     set->setTypeConstante(Settings::ENTIER);
                 }
                 else if(e.text() == "RATIONNEL")
                     set->setTypeConstante(Settings::RATIONNEL);
                 else if(e.text() == "REEL")
                     set->setTypeConstante(Settings::REEL);
                 else
                     throw LogMessage("Erreur lors du chargement du contexte", 2);
             }
             else if(e.nodeName() == "Complexe") {
                 if(e.text() == "NON_COMPLEXE")
                     set->setUtilisationDeComplexe(Settings::NON_COMPLEXE);
                 else if(e.text() == "COMPLEXE")
                     set->setUtilisationDeComplexe(Settings::COMPLEXE);
                 else
                     throw LogMessage("Erreur lors du chargement du contexte", 2);
             }
             else if(e.nodeName() == "NbElementAffichable") {
                 set->setNbElementAffichable(e.text().toInt());
             }
             else if(e.nodeName() == "ContenuPile") {
                 MainWindow::getInstance()->setInputLineEdit(e.text());
             }
         }
         n = n.nextSibling();
     }
     MainWindow::getInstance()->chargerContexte();
}
