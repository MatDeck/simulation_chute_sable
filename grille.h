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
        void changeCellule(int x, int y, Cellule* cellule);
        void changeCelluleDiagD(int x, int y, Cellule* cellule);
        void changeCelluleDiagG(int x, int y, Cellule* cellule);
        void changeCelluleD(int x, int y, Cellule* cellule);
        void changeCelluleG(int x, int y, Cellule* cellule);
        std::pair<int, int> getPosition(Cellule* cellule) const;
        void miseAJour();
};