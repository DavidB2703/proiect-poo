//
// Created by david on 3/12/2023.
//
#include "EndlessMaze.h"
#include <iostream>

///Functii Private



void EndlessMaze::initializare_variabile() {

    this->window = nullptr;
}

void EndlessMaze::initializare_fereastra() {
    this ->videoMode.height=600;
    this ->videoMode.width=800;
    this->window = new sf::RenderWindow(this ->videoMode,
                                        "Maze Game", sf::Style::Titlebar | sf::Style::Close );
    this -> window ->setFramerateLimit(144);

}


///Functii Publice




void EndlessMaze::render() {

    this->window->clear(sf::Color::Black);
    //Draw game
    tabla.draw(window);
    this ->window ->display();

}

void EndlessMaze::pollEvents() {

    while (this -> window ->pollEvent(this ->ev))
    {
        switch (this -> ev.type)
        {

            case sf::Event::Closed:
            {
                this->window->close();
                Tabla::afisare_nr_table();
            }
                break;
            case sf:: Event:: KeyPressed:
            {   int var=0;
                if( this-> ev.key.code == sf::Keyboard::Escape )
                    this->window->close(), Tabla::afisare_nr_table(), tabla.afisare_mutari();
                if ( this-> ev.key.code == sf::Keyboard::W )
                    tabla.move_jucator('W',var), tabla.numarare_mutari(), tabla.verificare_mutari();
                else if ( this-> ev.key.code == sf::Keyboard::A )
                    tabla.move_jucator('A',var), tabla.numarare_mutari(), tabla.verificare_mutari();
                else if ( this-> ev.key.code == sf::Keyboard::S )
                    tabla.move_jucator('S',var), tabla.numarare_mutari(), tabla.verificare_mutari();
                else if ( this-> ev.key.code == sf::Keyboard::D )
                    tabla.move_jucator('D',var), tabla.numarare_mutari(), tabla.verificare_mutari();
                if(var==1) {

                    Tabla tabla_noua;
                    Tabla::numarare_table();
                    tabla.afisare_mutari();
                    tabla.resetare_mutari();
                    tabla = tabla_noua;

                }


            }
                break;
            default: break;
        }
    }

}
///Constructori/Deconstructori/Operator=/Operator<<
EndlessMaze::EndlessMaze()   {
    this->initializare_variabile();
}
EndlessMaze::~EndlessMaze() {
    delete this->window;
    std:: cout<<"Destructorul clasei EndlessMaze\n";
}


///Accessors
bool EndlessMaze::running()  {
    return this->window->isOpen();
}

void EndlessMaze::closeWindow() {
    this->window->close();
}

void EndlessMaze::schimbare_tabla() {
    Tabla tabla_noua;
    tabla=tabla_noua;
}

void EndlessMaze::resetare_mutari() {
    this->tabla.resetare_mutari();
}

void EndlessMaze::afisare_table() {
    tabla.afisare_nr_table();
}

void EndlessMaze::resetare_numar_labirinturi() {
    tabla.resetare_contor();
}

void EndlessMaze::restartGame() {
    this -> closeWindow();
    this ->schimbare_tabla();
    this -> resetare_mutari();
    this -> afisare_table();
    this -> resetare_numar_labirinturi();
}









