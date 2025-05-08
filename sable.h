#pragma once

#include<iostream>
#include "cellule.h"
#include "grille.h"

class Sable : public Cellule {
    public:
        Sable(int x, int y);
        ~Sable();
        char getType() ;
        void miseAJour(Cellule* voisins[3][3], Grille& grille) override;
};
