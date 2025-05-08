#pragma once
#include "cellule.h"

Cellule::Cellule(int x, int y) : x(x), y(y), estVide(true) {}

Cellule::~Cellule() {}

char Cellule::getType() {
    return 'V'; 
}

void Cellule::miseAJour(Cellule* voisins[3][3], Grille& grille) {

}