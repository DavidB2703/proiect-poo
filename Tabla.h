//
// Created by david on 3/13/2023.
//

#ifndef OOP_TABLA_H
#define OOP_TABLA_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Interfata_joc.h"
using std::vector;

class eroare_endless_maze : public eroare_aplicatie {
public:
    explicit eroare_endless_maze(const std::string& mesaj) :
            eroare_aplicatie( mesaj) {}
};

class Tabla{
private:
    vector< vector<int>>matrice;
    vector< vector<sf::RectangleShape>> matrice_de_desenat;
    sf::RectangleShape jucator;
    sf::RectangleShape final;
    sf::Event event{};
    static int ct_tabla;
    int numar_mutari = 0;
    ///Functii private
public:
    ///Functii publice
     void numarare_mutari();
     void afisare_mutari() const;
    static void numarare_table();
    static void afisare_nr_table();
    void resetare_mutari();
    void verificare_mutari() const;
    void move_jucator(char c, int& var);
    void draw(sf::RenderWindow* window);
    void initializare_jucator(int x,int y);
    void initializare_final(int x,int y);

    void generare_tabla();
    void initializare_tabla();
    ///Constructori/Deconstructori/Operator=/Operator<<
    explicit Tabla();
    void resetare_contor();
    Tabla& operator=(const Tabla& other);
    ~Tabla();
};

#endif //OOP_TABLA_H
