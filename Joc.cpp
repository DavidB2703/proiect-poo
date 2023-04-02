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


///Functii Publice


void Joc::update() {

    this -> pollEvents();

}

void Joc::render() {

    this->window->clear(sf::Color::Black);
    //Draw game
    tabla.draw(window);
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
            {   int var=0;
                if( this-> ev.key.code == sf::Keyboard::Escape )
                    this->window->close();
                if ( this-> ev.key.code == sf::Keyboard::W )
                    tabla.move_jucator('W',var);
                else if ( this-> ev.key.code == sf::Keyboard::A )
                    tabla.move_jucator('A',var);
                else if ( this-> ev.key.code == sf::Keyboard::S )
                    tabla.move_jucator('S',var);
                else if ( this-> ev.key.code == sf::Keyboard::D )
                    tabla.move_jucator('D',var);
                if(var==1)
                {
                    Tabla tabla_noua;
                    tabla=tabla_noua;
                }
            }

                break;
            default: break;
        }
    }

}
///Constructori/Deconstructori/Operator=/Operator<<
Joc::Joc(int nivel_, int timer_) :  nivel{nivel_}, timer(timer_){
    this->initializare_variabile();
    this->initializare_fereastra();
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







