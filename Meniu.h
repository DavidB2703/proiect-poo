//
// Created by david on 4/15/2023.
//

#ifndef OOP_MENIU_H
#define OOP_MENIU_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Config.hpp>
#include "Interfata_joc.h"

class Meniu {
private:
    ///obiectele meniului
    sf::Font font;
    sf::Text titlu;
    sf::Text maze;
    sf::Text blocks;
    sf::Text guess;
    sf::RenderWindow* window{};
    sf::VideoMode videoMode;
    sf::Event ev{};
    sf::RectangleShape EndlessMaze;
    sf::RectangleShape FallingBlocks;
    sf::RectangleShape GuessTheNumber;
    std::vector<Interfata_joc*> jocuri;
    Interfata_joc* joc1{};
    Interfata_joc* joc2{};
    Interfata_joc* joc3{};
    ///Functii private
    void initializare_text();
    void initializare_variabile();
    void initializare_fereastra();
public:
    ///Functii publice
    void update() ;
    void render() ;
    void pollEvents() ;
    void initializare_casuta();
    void draw();
    ///constructoti destructori etc
    explicit Meniu();
    ~Meniu();
    bool running() ;
};



#endif //OOP_MENIU_H
