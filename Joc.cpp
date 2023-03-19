//
// Created by david on 3/12/2023.
//
#include "Joc.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
///Functii Private


void Joc::initializare_tabla() {

    tabla.matrice_de_desenat.resize(80);
    for(int i=0; i<40; i++)
    {     tabla.matrice_de_desenat[i].resize(60);
        for( int j=0; j<30; j++ )
            if ( tabla.matrice[i][j]==1 )
            {
                this -> tabla.matrice_de_desenat[i][j].setPosition(i*20.f,j*20.f);
                this -> tabla.matrice_de_desenat[i][j].setSize(sf::Vector2f(20.f,20.f));
                this -> tabla.matrice_de_desenat[i][j].setFillColor(sf::Color::Green);
                this -> tabla.matrice_de_desenat[i][j].setOutlineColor(sf::Color::Black);
                this -> tabla.matrice_de_desenat[i][j].setOutlineThickness(1.f);
            }
    }


}

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

    for(int i=0; i<80; i++)
        for( int j=0; j<60; j++ )
           if ( tabla.matrice[i][j]==1 )
                this ->window ->draw(tabla.matrice_de_desenat[i][j]);
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
    this -> initializare_tabla();
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

Joc &Joc::operator=(const Joc &other) {
    nivel = other.nivel;
    timer = other.timer;
    std :: cout<<"operator = de copiere al clasei Joc\n";
    return *this;
}

[[maybe_unused]] Joc::Joc(const Joc &other) :  nivel{other.nivel}, timer(other.timer){
    std:: cout<<"constructor de copiere al clasei Joc\n";
}

///Accessors

bool Joc::running() const {
    return this->window->isOpen();
}





