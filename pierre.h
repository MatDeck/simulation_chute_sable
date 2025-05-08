#pragma once

#include<iostream>
#include "cellule.h"

class Pierre : public Cellule {
    public:
        Pierre(int x, int y);
        ~Pierre();
        char getType()  override;
        void miseAJour(Cellule* voisins[3][3]) override;
};
