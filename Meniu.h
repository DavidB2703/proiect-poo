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
#include "Casuta_Joc.h"
class Meniu {
private:
    ///obiectele meniului
    sf::Font font;
    sf::Text titlu;
    sf::RenderWindow* window{};
    sf::VideoMode videoMode;
    sf::Event ev{};
    sf::View view;
    static const float sceneHeigh;
    ///Functii private
    void initializare_text();
    void initializare_variabile();
    void initializare_fereastra();
public:
    ///Functii publice
    void update(std::vector<Casuta_Joc> casute, std::vector<Interfata_joc*>  jocuri) ;
    void render(std::vector<Casuta_Joc> casute) ;
    void pollEvents(std::vector<Casuta_Joc> casute,std::vector<Interfata_joc*> jocuri) ;
    void draw(std::vector<Casuta_Joc> casute);
    ///constructoti destructori etc
    explicit Meniu();
    ~Meniu();
    bool running() ;
};



#endif //OOP_MENIU_H
