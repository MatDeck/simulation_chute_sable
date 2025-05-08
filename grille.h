#pragma once

#include <iostream>
#include <vector>
#include "cellule.h"

class Grille {
    private:
        int longueur;
        int largeur;
        std::vector<std::vector<Cellule*>> grille;
    public:
        Grille(int longueur, int largeur);
        ~Grille();
        Cellule* getCellule(int x, int y) const;
        void setCellule(int x, int y, Cellule* cellule);
        void miseAJour();
};