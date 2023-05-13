//
// Created by david on 5/8/2023.
//

#ifndef OOP_CASUTA_JOC_H
#define OOP_CASUTA_JOC_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Config.hpp>
#include "string"
class Casuta_Joc {
private:
    sf::RectangleShape casuta;
    std::string text;
    sf::Text sf_text;
    sf::Font font;
    static float x_scale;
public:
    explicit Casuta_Joc(std::string text);
    void initializare_variabile(float y_scale);
    bool isClicked(sf::RenderWindow* window, sf::Event event, sf::View view);
    bool isHovered(sf::RenderWindow* window, sf::Event event, sf::View view);
    void changeBackround();
    void changeBackroundBack();
    void draw(sf::RenderWindow* window);

};


#endif //OOP_CASUTA_JOC_H
