//
// Created by david on 4/19/2023.
//

#include "FallingBlocks.h"
#include <iostream>
///functii private
void FallingBlocks::draw() {
    this->window->draw(enemy);
    srand(time(nullptr));
    enemy.move(0.f,float(rand()%5));

    sf::FloatRect rectBounds = enemy.getGlobalBounds();
    sf::FloatRect windowBounds(sf::Vector2f(0.f, 0.f), static_cast<const sf::Vector2<float>>(window->getSize()));
    if (!rectBounds.intersects(windowBounds))
    {
        throw eroare_falling_blocks("Ai pierdut");
    }

}
void FallingBlocks::initializare_inamici() {
    int x_pos;
    x_pos=rand()%700;
    this -> enemy.setPosition(float(x_pos), 0.f);
    this -> enemy.setSize(sf::Vector2f(100.f, 100.f));
    this -> enemy.setFillColor(sf::Color::Green);
    this -> enemy.setOutlineColor(sf::Color::Black);
    this -> enemy.setOutlineThickness(5.f);
}

void FallingBlocks::numarare_inamici() {
    numar_inamici++;
}

void FallingBlocks::afisare_inamici() {
    std::cout<<"Numar de inamici omorati este: "<< numar_inamici<<"\n";
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


void FallingBlocks::render() {
    if(this->window!= nullptr)
    {
        this->window->clear(sf::Color::Black);
        ///draw game
        draw();
        this ->window ->display();
    }



}

void FallingBlocks::pollEvents() {
    if(this->window!= nullptr)
    {


    while (this -> window ->pollEvent(this ->ev))
    {
        switch (this -> ev.type)
        {

            case sf::Event::Closed:
                this->window->close(), afisare_inamici();
                break;
            case sf:: Event:: KeyPressed:
            {
                if( this-> ev.key.code == sf::Keyboard::Escape )
                    this->window->close(), afisare_inamici();
            }break;
            case sf::Event::MouseButtonPressed:
            {
                sf::FloatRect rectBounds = enemy.getGlobalBounds();
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                if (rectBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                {
                    // Do something when the rectangle is clicked
                    numarare_inamici();
                    initializare_inamici();
                    draw();

                }
                else
                {
                    throw eroare_falling_blocks("nu ai voie ai sa dai click in afara patratului");
                }


            }break;
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

            }break;
            default: break;
        }

    }
    }
}


FallingBlocks::FallingBlocks() {

    srand(time(nullptr));
    numar_inamici = 0;
    this->initializare_variabile();
    this->initializare_inamici();
}

FallingBlocks::~FallingBlocks() {

    delete this->window;
    FallingBlocks::afisare_inamici();

}
///Accesors
bool FallingBlocks::running() {
    if(this->window!= nullptr)
        return this->window->isOpen();
    return false;
}







