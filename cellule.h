#pragma once

#include <iostream>

class Grille;

class Cellule {
    protected:
        int x; 
        int y; 
        bool estVide; 
    public:
        Cellule(int x, int y);
         ~Cellule();
        virtual char getType();
        virtual void miseAJour(Cellule* voisins[3][3], Grille& grille);
};
