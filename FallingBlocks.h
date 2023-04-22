//
// Created by david on 4/19/2023.
//

#ifndef OOP_FALLINGBLOCKS_H
#define OOP_FALLINGBLOCKS_H
#include "Interfata_joc.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Config.hpp>
#include <stdexcept>
#include <string>



class eroare_falling_blocks : public eroare_aplicatie {
public:
    explicit eroare_falling_blocks(std::string mesaj) :
            eroare_aplicatie( mesaj) {}
};
class FallingBlocks: public Interfata_joc {
private:
    ///obiectele jocului
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;
    sf::RenderWindow *window{};
    sf::VideoMode videoMode;
    sf::Event ev{};
    ///functii private
    void initializare_variabile();
    void initializare_fereastra();
    void initializare_inamici();
    void draw();
public:
    ///Functii
    void update() override;
    void render() override;
    void pollEvents() override;
    ///Constructori/Deconstructori/Operator=/Operator<<
    explicit FallingBlocks();
    ~FallingBlocks();
    ///Accesors
     bool running() ;
};


#endif //OOP_FALLINGBLOCKS_H