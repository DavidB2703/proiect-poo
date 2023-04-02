//
// Created by david on 3/13/2023.
//

#ifndef OOP_TABLA_H
#define OOP_TABLA_H
#include "Perete.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using std::vector;

class Tabla{
private:
    int dimensiune;
    vector <Perete> vec;
    vector< vector<int>>matrice;
    vector< vector<sf::RectangleShape>> matrice_de_desenat;
    sf::RectangleShape jucator;
    sf::RectangleShape final;
    sf::Event event{};
    ///Functii private
public:

    ///Functii publice
    void move_jucator(char c, int& var);
    void draw(sf::RenderWindow* window);
    void initializare_jucator(int x,int y);
    void initializare_final(int x,int y);

    void generare_tabla();
    void initializare_tabla();
    ///Constructori/Deconstructori/Operator=/Operator<<
    explicit Tabla( int dimensiune_=4, const std::vector <Perete>& vec_ = {Perete{1,2}, Perete{4,5}, Perete{1,3},Perete{6,5}} );

    [[maybe_unused]] Tabla( const Tabla& other );
    Tabla& operator=(const Tabla& other);
    ~Tabla();
    friend std :: ostream& operator<<(std::ostream& os, const Tabla& tabla);
};

#endif //OOP_TABLA_H
