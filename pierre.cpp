#pragma once
#include "pierre.h"
#include "grille.h"

Pierre::Pierre(int x, int y) : Cellule(x, y) {
    estVide = false;
}

Pierre::~Pierre() {
    
}

char Pierre::getType()  {
    return 'P'; 
}

void Pierre::miseAJour(Cellule* voisins[3][3], Grille& grille) {
    
}