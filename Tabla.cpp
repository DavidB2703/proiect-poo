//
// Created by david on 3/13/2023.
//

#include "Tabla.h"
#include <vector>
using std::vector;
///Functii publice

void Tabla::draw(sf::RenderWindow* window) {
        int lenght=80,width=60;
        for(int i=0; i<lenght; i++)
        for( int j=0; j<width; j++ )
           if ( matrice[i][j]==1 )
                window->draw(matrice_de_desenat[i][j]);
}


void Tabla::initializare_tabla() {
    int heigh=60, lenght=80;
    matrice_de_desenat.resize(lenght);
    for(int i=0; i<lenght/2; i++)
    {     matrice_de_desenat[i].resize(heigh);
        for( int j=0; j<heigh/2; j++ )
            if ( matrice[i][j]==1 )
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
    int lenght=80, width=60;
    matrice.resize(lenght,vector<int>(width));
    for (int i=1;i<20;i++)
        matrice[i][1]=1;
    for(int j=1;j<29;j++)
        matrice[19][j]=1;
    for(int i=19; i<39;i++)
    {
        matrice[i][7]=1;
        matrice[i][11]=1;

    }
    for(int j=1;j<29;j++)
        matrice[11][j]=1;
    for(int i=0; i<19;i++)
        matrice[i][12]=1;
    for(int j=11;j<29;j++)
        matrice[11][j]=1;


}



///Constructori/Deconstructori/Operator=/Operator<<
Tabla::Tabla(int dimensiune_, const std::vector<Perete> &vec_) :
        dimensiune{dimensiune_}, vec{vec_}{
        this->generare_tabla();
        this->initializare_tabla();
    std :: cout<<"Constructor de initializere al clasei Tabla\n";
}

[[maybe_unused]] Tabla::Tabla(const Tabla &other) : dimensiune{other.dimensiune}, vec{other.vec}{
    this->generare_tabla();
    std :: cout<<"Constructor de copiere al clasei Tabla\n";

}

Tabla &Tabla::operator=(const Tabla &other) {
    dimensiune= other.dimensiune;
    vec = other.vec;
    std :: cout<<"operator = de copiere al clasei Tabla\n";
    return *this;
}

Tabla::~Tabla() {
    std:: cout<<"Destructorul clasei Tabla\n";
}

std::ostream &operator<<(std::ostream &os, const Tabla &tabla) {
    os << "Tabla are dimensiunea:" << tabla.dimensiune<< " \n";
    return os;
}