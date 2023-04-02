//
// Created by david on 3/12/2023.
//

#ifndef OOP_JOC_H
#define OOP_JOC_H
#include <iostream>
#include "Tabla.h"
class Joc{
private:
    ///Variabile
    int nivel=1;
    int timer;
    ///Fereastra

    sf::RenderWindow* window{};
    sf::VideoMode videoMode;
    sf::Event ev{};

    ///Obiectele jocului
    Tabla tabla;
    ///Functii private
    void initializare_variabile();
    void initializare_fereastra();
public:
    ///Functii
    void update();
    void render();
    void pollEvents();
    ///Constructori/Deconstructori/Operator=/Operator<<
    explicit Joc(  int nivel_=1, int timer_=0);
    ~Joc();
    friend std :: ostream& operator<<(std::ostream& os, const Joc& joc);
    ///Accesors
    bool running() const;
};

#endif //OOP_JOC_H
