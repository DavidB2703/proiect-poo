//
// Created by david on 4/10/2023.
//

#ifndef OOP_INTERFATA_JOC_H
#define OOP_INTERFATA_JOC_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class eroare_aplicatie : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class Interfata_joc {

public:
    virtual void update()=0;
    virtual void render()=0;
    virtual void pollEvents()=0;
    virtual bool running()=0;
    explicit Interfata_joc(){
        std::cout<<"CONSTRUCTOR CLASA DE BAZA\n";
    }
    virtual ~Interfata_joc()= default;
};


#endif //OOP_INTERFATA_JOC_H
