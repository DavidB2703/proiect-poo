//
// Created by david on 3/12/2023.
//

#ifndef OOP_ENDLESSMAZE_H
#define OOP_ENDLESSMAZE_H
#include <iostream>
#include "Tabla.h"
#include "Interfata_joc.h"



class EndlessMaze : public Interfata_joc {
private:
    ///Variabile

    ///Fereastra

    sf::RenderWindow* window{};
    sf::VideoMode videoMode;
    sf::Event ev{};
    ///Obiectele jocului
    Tabla tabla;
    ///Functii private
    void initializare_variabile();
public:
    ///Functii
    void render() override;
    void pollEvents() override;
    void initializare_fereastra() override;
    void restartGame() override;
    ///Constructori/Deconstructori/Operator=/Operator<<
    explicit EndlessMaze();
    ~EndlessMaze();
    ///Accesors
    bool running() override;

};

#endif //OOP_ENDLESSMAZE_H
