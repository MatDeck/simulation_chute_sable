#pragma once
#include "simulation.h"
#include <iostream>

int main() {
    int gridWidth, gridHeight;
    std::cout << "Entrez la largeur de la grille (en nombre de cellules) : ";
    std::cin >> gridWidth;
    std::cout << "Entrez la hauteur de la grille (en nombre de cellules) : ";
    std::cin >> gridHeight;
    if (gridWidth <= 0 || gridHeight <= 0) {
        std::cerr << "La taille de la grille doit être positive !" << std::endl;
        return 1;
    }
    const int cellSize = 20;
    Simulation simulation(gridWidth, gridHeight, cellSize);
    simulation.run();
    return 0;
}