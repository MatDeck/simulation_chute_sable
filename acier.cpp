#pragma once
#include "Acier.h"
#include "grille.h"

Acier::Acier(int x, int y) : Cellule(x, y) {
    estVide = false;
}

Acier::~Acier() {

}

char Acier::getType() {
    return 'A';
}

void Acier::miseAJour(Cellule* voisins[3][3], Grille& grille) {

}