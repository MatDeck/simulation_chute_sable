#pragma  once

#include "grille.h"
#include <algorithm>

Grille::Grille(int longueur, int largeur) : longueur(longueur), largeur(largeur) {
    grille.resize(longueur, std::vector<Cellule*>(largeur, nullptr));
    for (int x = 0; x < longueur; ++x) {
        for (int y = 0; y < largeur; ++y) {
            grille[x][y] = new Cellule(x, y); 
        }
    }
}

Grille::~Grille() {
    for (auto& ligne : grille) {
        for (auto& cellule : ligne) {
            delete cellule;
        }
    }
}

Cellule* Grille::getCellule(int x, int y) const {
    if (x >= 0 && x < longueur && y >= 0 && y < largeur) {
        return grille[x][y];
    }
    return nullptr;
}

void Grille::setCellule(int x, int y, Cellule* cellule) {
    if (x >= 0 && x < longueur && y >= 0 && y < largeur) {
        delete grille[x][y];
        grille[x][y] = cellule;
    }
}

void Grille::changeCellule(int x, int y, Cellule* cellule) {
    if (x >= 0 && x < longueur && y >= 0 && y < largeur) {
        if (y < (largeur - 1)) {
            Cellule* temp = grille[x][y + 1];
            grille[x][y + 1] = grille[x][y];
            grille[x][y] = temp;
        }
    }
}

std::pair<int, int> Grille::getPosition(Cellule* cellule) const {
    for (int x = 0; x < longueur; ++x) {
        for (int y = 0; y < largeur; ++y) {
            if (grille[x][y] == cellule) {
                return { x, y };
            }
        }
    }
    return { -1, -1 }; 
}

void Grille::miseAJour() {
    for (int y = largeur - 1; y >= 0; --y) {
        for (int x = 0; x < longueur; ++x) {
            if (grille[x][y]) {
                Cellule* voisins[3][3] = { nullptr };
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        voisins[dx + 1][dy + 1] = getCellule(x + dx, y + dy);
                    }
                }
                grille[x][y]->miseAJour(voisins, *this);
            }
        }
    }
}
