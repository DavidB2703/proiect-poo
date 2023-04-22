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

class Meniu: public Interfata_joc {
private:
    ///obiectele meniului
    sf::Font font;
    sf::Text titlu;
    sf::Text maze;
    sf::Text blocks;
    sf::RenderWindow* window{};
    sf::VideoMode videoMode;
    sf::Event ev{};
    sf::RectangleShape EndlessMaze;
    sf::RectangleShape FallingBlocks;
    void initializare_text();
    void initializare_variabile();
    void initializare_fereastra();
    //void initializare_text();
public:
    ///Functii publice
    void update() override;
    void render() override;
    void pollEvents() override;
    void initializare_casuta();
    void draw();
    ///constructoti destructori etc
    explicit Meniu();
    ~Meniu();
    bool running() const;

};



#endif //OOP_MENIU_H
