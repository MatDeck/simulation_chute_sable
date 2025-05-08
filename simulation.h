#pragma once
#include <SFML/Graphics.hpp>
#include "grille.h"

class Simulation {
private:
    int gridWidth;       
    int gridHeight;      
    int cellSize;        
    Grille grille;       
    sf::RenderWindow window; 
    char materiauSelectionne;

public:
    Simulation(int gridWidth, int gridHeight, int cellSize);
    void run();
private:
    void processEvents();
    void update();
    void render();
};
