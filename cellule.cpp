#include "cellule.h"

Cellule::Cellule(int x, int y) : x(x), y(y), estVide(true) {}

Cellule::~Cellule() {}

char Cellule::getType() const {
    return 'V'; // Par défaut, vide ('V' pour "vide")
}