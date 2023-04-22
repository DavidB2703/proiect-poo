//
// Created by david on 4/19/2023.
//

#include "FallingBlocks.h"
#include <iostream>
///functii private
void FallingBlocks::draw() {
    this->window->draw(enemy);
    srand(time(nullptr));
    enemy.move(0.f,rand()%5);
}
void FallingBlocks::initializare_inamici() {
    int x_pos;
    x_pos=rand()%800;
    this -> enemy.setPosition(x_pos, 0.f);
    this -> enemy.setSize(sf::Vector2f(100.f, 100.f));
    this -> enemy.setFillColor(sf::Color::Green);
    this -> enemy.setOutlineColor(sf::Color::Black);
    this -> enemy.setOutlineThickness(5.f);
}


void FallingBlocks::initializare_variabile() {

    this->window = nullptr;

}

void FallingBlocks::initializare_fereastra() {
    this ->videoMode.height=600;
    this ->videoMode.width=800;
    this->window = new sf::RenderWindow(this ->videoMode,
                                        "Falling Blocks", sf::Style::Titlebar | sf::Style::Close );
    this -> window ->setFramerateLimit(144);

}
///functii publice


void FallingBlocks::update() {

    this -> pollEvents();

}

void FallingBlocks::render() {

    this->window->clear(sf::Color::Black);
    ///draw game
    draw();
    this ->window ->display();

}

void FallingBlocks::pollEvents() {

    while (this -> window ->pollEvent(this ->ev))
    {
        switch (this -> ev.type)
        {

            case sf::Event::Closed:
                this->window->close();
                break;
            case sf:: Event:: KeyPressed:
            {
                if( this-> ev.key.code == sf::Keyboard::Escape )
                    this->window->close();
            }
                break;
            default: break;
            case sf::Event::MouseButtonPressed:
            {
                sf::FloatRect rectBounds = enemy.getGlobalBounds();
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                if (rectBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                {
                    // Do something when the rectangle is clicked
                    initializare_inamici();
                    draw();
                }
                else
                {
                    throw eroare_falling_blocks("nu ai voie ai sa dai click in afara patratului");
                }


            }
            case sf::Event::MouseMoved:
            {
                // Check if the mouse is within the bounds of the rectangle
                sf::FloatRect rectBounds = enemy.getGlobalBounds();

                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                if (rectBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                {
                    // Do something when the mouse is over the rectangle
                    enemy.setFillColor(sf::Color::Red);
                }
                else
                {
                    // Reset the color of the rectangle when the mouse is not over it
                    enemy.setFillColor(sf::Color::Green);
                }
            }

        }

    }
}


FallingBlocks::FallingBlocks() {

    srand(time(nullptr));

    this->initializare_variabile();
    this->initializare_fereastra();
    this->initializare_inamici();
}

FallingBlocks::~FallingBlocks() {
    delete this->window;
}
///Accesors
bool FallingBlocks::running() {
     return this->window->isOpen();
}


