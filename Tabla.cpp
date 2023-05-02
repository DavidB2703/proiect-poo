//
// Created by david on 3/13/2023.
//

#include "Tabla.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using std::vector;
///Functii publice

void Tabla::numarare_mutari() {
    numar_mutari++;
}
void Tabla::afisare_mutari() {
    std::cout<<"Numarul de mutari facute este: "<< numar_mutari <<"\n";
}

void Tabla::afisare_nr_table() {
    std::cout<<"Numarul de labirinturi parcurse este: "<<ct_tabla<<"\n";
}


void Tabla::numarare_table() {
    ct_tabla++;
}


void Tabla::move_jucator(char c,int& var) {
    sf::Vector2f position = jucator.getPosition();
    int x=int(position.x)/20, y=int(position.y)/20;
    if (c=='W')
    {
        if(matrice[x][y-1] !=0)
            jucator.move(0.f,-20.f);
        else throw eroare_endless_maze("Nu ai voie sa mergi in afara patratelelor verzi\n");
    }
    if (c=='A' )
    {
        if(matrice[x-1][y] !=0)
        jucator.move(-20.f,0.f);
        else throw eroare_endless_maze("Nu ai voie sa mergi in afara patratelelor verzi\n");
    }

    if (c=='S')
    {
        if(matrice[x][y+1] !=0)
            jucator.move(0.f,20.f);
        else throw eroare_endless_maze("Nu ai voie sa mergi in afara patratelelor verzi\n");
    }


    if (c=='D'){
        if(matrice[x+1][y]!=0)
        jucator.move(20.f,0.f);
        else throw eroare_endless_maze("Nu ai voie sa mergi in afara patratelelor verzi\n");
    }

    sf::Vector2f position_final=final.getPosition();
    sf::Vector2f position1 = jucator.getPosition();
    if( position1.x==position_final.x and position1.y==position_final.y )
        var=1;


}

void Tabla::initializare_final(int x, int y) {
    this -> final.setPosition(y*20,x*20);
    this -> final.setSize(sf::Vector2f(20.f,20.f));
    this -> final.setFillColor(sf::Color::Red);
    this -> final.setOutlineColor(sf::Color::Black);
    this -> final.setOutlineThickness(1.f);
}

void Tabla::initializare_jucator(int x, int y) {
    this -> jucator.setPosition(y*20,x*20);
    this -> jucator.setSize(sf::Vector2f(20.f,20.f));
    this -> jucator.setFillColor(sf::Color::Blue);
    this -> jucator.setOutlineColor(sf::Color::Black);
    this -> jucator.setOutlineThickness(1.f);
}

void Tabla::draw(sf::RenderWindow* window) {
        int lenght=80,width=60;
        for(int i=0; i<lenght; i++)
        for( int j=0; j<width; j++ )
           if ( matrice[i][j]!=0)
                window->draw(matrice_de_desenat[i][j]);
    for(int i=0; i<lenght; i++)
        for( int j=0; j<width; j++ )
             if(matrice[i][j]==2)
           {
               window->draw(jucator);
               window->draw(final);
           }
}


void Tabla::initializare_tabla() {
    int heigh=60, length=80;
    matrice_de_desenat.resize(length);
    for(int i=0; i<length/2; i++)
    {     matrice_de_desenat[i].resize(heigh);
        for( int j=0; j<heigh/2; j++ )
            if ( matrice[i][j]!=0 )
            {
                this -> matrice_de_desenat[i][j].setPosition(i*20.f,j*20.f);
                this -> matrice_de_desenat[i][j].setSize(sf::Vector2f(20.f,20.f));
                this -> matrice_de_desenat[i][j].setFillColor(sf::Color::Green);
                this -> matrice_de_desenat[i][j].setOutlineColor(sf::Color::Black);
                this -> matrice_de_desenat[i][j].setOutlineThickness(1.f);
            }
    }


}
void Tabla::generare_tabla() {
    int length=80, width=60;
    matrice.resize(length,vector<int>(width));
    //pattern principal
    srand(time(nullptr));
    int x_start=rand()%30, y_start=rand()%40, x_end=rand()%30, y_end=rand()%40;
    initializare_jucator(x_start,y_start);
    matrice[y_start][x_start]=2;
    initializare_final(x_end,y_end);
    matrice[y_end][x_end]=2;
    while( (x_start != x_end) || (y_start != y_end) ) {
        int ct_x = 1, ct_y = 1;
        if (x_start > x_end)
            ct_x = -1;
        if (y_start > y_end)
            ct_y = -1;
        int random = rand() % 2;
        if (random == 1)
        {
            if(y_start<=60)
                y_start += ct_y;
        }
        else
            if(x_start<=80)
                x_start += ct_x;
        if(matrice[y_start][x_start]==0)
            matrice[y_start][x_start] = 1;
    }


}



///Constructori/Deconstructori/Operator=/Operator<<
Tabla::Tabla()
        {
        this->generare_tabla();
        this->initializare_tabla();
    std :: cout<<"Constructor de initializere al clasei Tabla\n";
}



Tabla &Tabla::operator=(const Tabla &other) {
    matrice=other.matrice;
    matrice_de_desenat=other.matrice_de_desenat;
    jucator=other.jucator;
    final=other.final;
    event=other.event;
    return *this;
}

Tabla::~Tabla() {
    std:: cout<<"Destructorul clasei Tabla\n";
}










