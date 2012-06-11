/*!
 \file historique.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 03 Juin 2012
 \version 1.0
 */

#ifndef HISTORIQUE_H
#define HISTORIQUE_H

/*!
  \class Historique
  \brief ...
  */
class Historique {
public:
    virtual void undo()=0;
    virtual void redo()=0;
};

#endif
