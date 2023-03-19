//
// Created by david on 3/13/2023.
//

#include "Tabla.h"
#include <vector>
//#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
using std::vector;
///Functii publice


void Tabla::generare_tabla() {
    matrice.resize(80,vector<int>(60));
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



//void Tabla::stergere_tabla(mat) {
//    for(int j=0;j<60;j++)
//        delete []mat[j];
//    delete[]mat[];
//    mat=0;
//}
