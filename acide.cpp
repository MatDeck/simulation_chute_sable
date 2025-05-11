#pragma once
#include "Acide.h"
#include "grille.h"

Acide::Acide(int x, int y) : Cellule(x, y) {
    estVide = false;
    cor_sable = 30;
    cor_pierre = 10;
}

Acide::~Acide() {

}

char Acide::getType() {
    return 'C';
}

void Acide::miseAJour(Cellule* voisins[3][3], Grille& grille) {
    std::pair<int, int> position = grille.getPosition(this);
    int x = position.first;
    int y = position.second;
    if (voisins[1][2] && voisins[1][2]->getType() == 'P') {
        cor_pierre--;
        if (cor_pierre == 0) {
            grille.setCellule(x, y + 1, new Cellule(x, y + 1));
            grille.setCellule(x, y, new Cellule(x, y));
            return;
        }
        return;
    }
    if (voisins[1][2] && voisins[1][2]->getType() == 'S') {
        cor_sable--;
        if (cor_sable == 0) {
            grille.setCellule(x, y + 1, new Cellule(x, y + 1));
            grille.setCellule(x, y, new Cellule(x, y));
            return;
        }
        return;
    }
    if (voisins[1][2] && voisins[1][2]->getType() == 'V') {
        grille.changeCellule(x, y, this);
        return;
    }
    else if (voisins[2][1] && voisins[2][1]->getType() == 'V') {
        grille.changeCelluleD(x, y, this);
        return;
    }
    else if (voisins[0][1] && voisins[0][1]->getType() == 'V') {
        grille.changeCelluleG(x, y, this);
        return;
    }
}