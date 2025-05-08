#pragma once
#include "sable.h"
#include "grille.h"

Sable::Sable(int x, int y) : Cellule(x, y) {
    estVide = false; 
}

Sable::~Sable() {
    
}

char Sable::getType() {
    return 'S'; 
}

void Sable::miseAJour(Cellule* voisins[3][3], Grille& grille) {
    std::pair<int, int> position = grille.getPosition(this);
    int x = position.first;
    int y = position.second;
    if (voisins[1][2] && voisins[1][2]->getType() == 'V') {
        grille.setCellule(x, y + 1, this);
        grille.setCellule(x, y, new Cellule(x, y));
        return;
    }
    if (voisins[2][2] && voisins[2][2]->getType() == 'V') {
        grille.setCellule(x + 1, y + 1, this);
        grille.setCellule(x, y, new Cellule(x, y));
        return;
    }
    if (voisins[0][2] && voisins[0][2]->getType() == 'V') {
        grille.setCellule(x - 1, y + 1, this);
        grille.setCellule(x, y, new Cellule(x, y));
        return;
    }
}