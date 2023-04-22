//
// Created by david on 3/12/2023.
//

#ifndef OOP_JOC_H
#define OOP_JOC_H
#include <iostream>
#include "Tabla.h"
#include "Interfata_joc.h"
class Joc : public Interfata_joc {
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
    void initializare_fereastra();
public:
    ///Functii
    void update() override;
    void render() override;
    void pollEvents() override;
    ///Constructori/Deconstructori/Operator=/Operator<<
    explicit Joc();
    ~Joc();
    ///Accesors
    bool running() const;
};

#endif //OOP_JOC_H
