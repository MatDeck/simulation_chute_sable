#pragma once

#include<iostream>
#include "cellule.h"

class Acide : public Cellule {
    private:
        int cor_sable;
        int cor_pierre;
    public:
        Acide(int x, int y);
        ~Acide();
        char getType();
        void miseAJour(Cellule* voisins[3][3], Grille& grille) override;
};
