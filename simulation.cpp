#pragma once
#include "simulation.h"
#include "sable.h"
#include "pierre.h"
#include <iostream>

Simulation::Simulation(int gridWidth, int gridHeight, int cellSize)
    : gridWidth(gridWidth),
    gridHeight(gridHeight),
    cellSize(cellSize),
    grille(gridWidth, gridHeight),
    window(sf::VideoMode(gridWidth* cellSize, gridHeight* cellSize), "Simulation de chute de sable"),
    materiauSelectionne('S') 
{
}

void Simulation::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Simulation::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::S) {
                materiauSelectionne = 'S'; 
            }
            else if (event.key.code == sf::Keyboard::P) {
                materiauSelectionne = 'P'; 
            }
            else if (event.key.code == sf::Keyboard::V) {
                materiauSelectionne = 'V'; 
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            int x = event.mouseButton.x / cellSize;
            int y = event.mouseButton.y / cellSize;

            if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
                if (materiauSelectionne == 'S') {
                    grille.setCellule(x, y, new Sable(x, y));
                }
                else if (materiauSelectionne == 'P') {
                    grille.setCellule(x, y, new Pierre(x, y));
                }
                else if (materiauSelectionne == 'V') {
                    grille.setCellule(x, y, nullptr); 
                }
            }
        }
    }
}

void Simulation::update() {
    grille.miseAJour();
}

void Simulation::render() {
    window.clear();
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            Cellule* cellule = grille.getCellule(x, y);
            sf::RectangleShape rectangle(sf::Vector2f(cellSize, cellSize));
            rectangle.setPosition(x * cellSize, y * cellSize);
            if (cellule->getType() == 'V') {
                rectangle.setFillColor(sf::Color::Black);
            }
            else if (cellule->getType() == 'S') {
                rectangle.setFillColor(sf::Color::Yellow); 
            }
            else if (cellule->getType() == 'P') {
                rectangle.setFillColor(sf::Color::White); 
            }
            window.draw(rectangle);
        }
    }
    window.display();
}