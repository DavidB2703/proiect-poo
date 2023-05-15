//
// Created by david on 5/8/2023.
//

#include "Casuta_Joc.h"

#include <utility>
#include <iostream>

void Casuta_Joc::initializare_variabile(float y_scale) {


    font.loadFromFile(R"(arial.ttf)");
    this -> sf_text.setFont(font);
    this -> sf_text.setString(text);
    this -> sf_text.setCharacterSize(25);
    this -> sf_text.setPosition(x_scale+30, y_scale+30);
    this -> sf_text.setFillColor(sf::Color::White);

    this -> casuta.setPosition(x_scale, y_scale);
    this -> casuta.setSize(sf::Vector2f(200.f, 100.f));
    this -> casuta.setFillColor(sf::Color::Red);
    this -> casuta.setOutlineColor(sf::Color::Black);
    this -> casuta.setOutlineThickness(5.f);

}

Casuta_Joc::Casuta_Joc(std::string text) : text(std::move(text)) {
}

bool Casuta_Joc::isClicked(sf::RenderWindow* window, sf::Event event, sf::View view) {

    sf::Vector2f mousePosition = window->mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y), view);

    // Check if the mouse is over the button
    if (casuta.getGlobalBounds().contains(mousePosition))
        return true;
    return false;

}

bool Casuta_Joc::isHovered(sf::RenderWindow* window, sf::Event event, sf::View view) {
    // Get the mouse position relative to the window
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

    // Convert the mouse position to world coordinates using the provided view
    sf::Vector2f worldMousePosition = window->mapPixelToCoords(mousePosition, view);

    // Check if the mouse is inside the rectangle's bounds
    if (casuta.getGlobalBounds().contains(worldMousePosition)) {
        // Mouse is hovering over the rectangle
        return true;
    } else {
        // Mouse is not hovering over the rectangle
        return false;
    }
}

void Casuta_Joc::changeBackround() {
    this -> casuta.setFillColor(sf::Color::Blue);
}

void Casuta_Joc::draw(sf::RenderWindow *window) {
    window->draw(casuta);
    window->draw(sf_text);
}

void Casuta_Joc::changeBackroundBack() {
    this -> casuta.setFillColor(sf::Color::Red);
}
