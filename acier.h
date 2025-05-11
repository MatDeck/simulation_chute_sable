#pragma once

#include<iostream>
#include "cellule.h"

class Acier : public Cellule {
public:
    Acier(int x, int y);
    ~Acier();
    char getType()  override;
    void miseAJour(Cellule* voisins[3][3], Grille& grille) override;
};
