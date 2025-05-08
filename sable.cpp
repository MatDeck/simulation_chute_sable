#pragma once
#include "sable.h"
#include <utility>

Sable::Sable(int x, int y) : Cellule(x, y) {
    estVide = false; 
}

Sable::~Sable() {
    
}

char Sable::getType() {
    return 'S'; 
}

void Sable::miseAJour(Cellule* voisins[3][3]) {
    if (voisins[1][2]->getType() == 'V') {
        std::swap(voisins[1][2], voisins[1][1]);
        return;
    }
    if (voisins[2][2]->getType() == 'V') {
        std::swap(voisins[2][2], voisins[1][1]);
        return;
    }
    if (voisins[0][2]->getType() == 'V') {
        std::swap(voisins[0][2], voisins[1][1]);
        return;
    }
}