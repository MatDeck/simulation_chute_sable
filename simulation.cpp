#pragma once
#include "simulation.h"
#include "sable.h"
#include "pierre.h"
#include "acier.h"
#include "acide.h"
#include <iostream>

Simulation::Simulation(int gridWidth, int gridHeight, int cellSize)
    : gridWidth(gridWidth),
    gridHeight(gridHeight),
    cellSize(cellSize),
    grille(gridWidth, gridHeight),
    window(sf::VideoMode(gridWidth* cellSize, gridHeight* cellSize), "Simulation de chute de sable"),
    materiauSelectionne('P') 
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
            else if (event.key.code == sf::Keyboard::A) {
                materiauSelectionne = 'A';
            }
            else if (event.key.code == sf::Keyboard::C) {
                materiauSelectionne = 'C';
            }
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i sourisPixel = sf::Mouse::getPosition(window);
        int x = sourisPixel.x / cellSize;
        int y = sourisPixel.y / cellSize;

        if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
            if (materiauSelectionne == 'S') {
                grille.setCellule(x, y, new Sable(x, y));
            }
            else if (materiauSelectionne == 'P') {
                grille.setCellule(x, y, new Pierre(x, y));
            }
            else if (materiauSelectionne == 'V') {
                grille.setCellule(x, y, new Cellule(x, y));
            }
            else if (materiauSelectionne == 'A') {
                grille.setCellule(x, y, new Acier(x, y));
            }
            else if (materiauSelectionne == 'C') {
                grille.setCellule(x, y, new Acide(x, y));
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
            if (cellule == nullptr) {
                rectangle.setFillColor(sf::Color::Transparent);
            } 
            else if (cellule->getType() == 'V') {
                rectangle.setFillColor(sf::Color::Black);
            }
            else if (cellule->getType() == 'S') {
                rectangle.setFillColor(sf::Color::Yellow); 
            }
            else if (cellule->getType() == 'P') {
                rectangle.setFillColor(sf::Color::White); 
            }
            else if (cellule->getType() == 'A') {
                rectangle.setFillColor(sf::Color(128, 128, 128));
            }
            else if (cellule->getType() == 'C') {
                rectangle.setFillColor(sf::Color::Green);
            }
            window.draw(rectangle);
        }
    }
    window.display();
}