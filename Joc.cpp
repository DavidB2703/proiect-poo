//
// Created by david on 3/12/2023.
//
#include "Joc.h"
#include <iostream>
///Functii Private

void Joc::initializare_variabile() {

    this->window = nullptr;

}

void Joc::initializare_fereastra() {
    this ->videoMode.height=600;
    this ->videoMode.width=800;
    this->window = new sf::RenderWindow(this ->videoMode,
                                        "Maze Game", sf::Style::Titlebar | sf::Style::Close );
    this -> window ->setFramerateLimit(144);
}

void Joc::initializare_jucator() {
    this -> jucator.setPosition(0.f,20.f);
    this -> jucator.setSize(sf::Vector2f(20.f,20.f));
    this -> jucator.setFillColor(sf::Color::Blue);
    this -> jucator.setOutlineColor(sf::Color::Green);
    this -> jucator.setOutlineThickness(1.f);

}


///Functii Publice

void Joc::update() {

    this -> pollEvents();

}

void Joc::render() {

    this->window->clear(sf::Color::Black);

    //Draw game
    tabla.draw(window);
    this ->window ->draw(this->jucator);

    this ->window ->display();

}

void Joc::pollEvents() {

    while (this -> window ->pollEvent(this ->ev))
    {
        switch (this -> ev.type)
        {

            case sf::Event::Closed:
                this->window->close();
                break;
            case sf:: Event:: KeyPressed:
                if( this-> ev.key.code == sf::Keyboard::Escape )
                    this->window->close();
                break;
            default: break;
        }
    }

}
///Constructori/Deconstructori/Operator=/Operator<<
Joc::Joc(int nivel_, int timer_) :  nivel{nivel_}, timer(timer_){
    this->initializare_variabile();
    this->initializare_fereastra();
    this -> initializare_jucator();

    std:: cout<<"constructor de initializare al clasei Joc\n";
}
Joc::~Joc() {
    delete this->window;
    std:: cout<<"Destructorul clasei Joc\n";
}

std::ostream &operator<<(std::ostream &os, const Joc &joc) {
    os << "Nivelul jocului este " << joc.nivel << " iar timpul este: " << joc.timer << " \n";
    return os;
}
///Accessors
bool Joc::running() const {
    return this->window->isOpen();
}





