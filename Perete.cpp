//
// Created by david on 3/12/2023.
//

#include "Perete.h"

Perete::Perete(int coor_x_, int coor_y_) : coor_x{coor_x_}, coor_y{coor_y_} {
    std:: cout<<"constructor de initializere al clasei Perete\n";
}

Perete::Perete(const Perete &other) : coor_x{other.coor_x}, coor_y{other.coor_y}{
    std:: cout<<"constructor de copiere al clasei Perete\n";
}

Perete &Perete::operator=(const Perete &other) {
    coor_x= other.coor_x;
    coor_y= other.coor_y;
    std :: cout<<"operator = de copiere al clasei Perete\n";
    return *this;
}

Perete::~Perete() {
    std:: cout<<"Destructorul clasei Perete\n";
}

std::ostream &operator<<(std::ostream &os, const Perete &perete) {
    os<<"La coordonatele x= "<<perete.coor_x<<" si y= "<<perete.coor_y<<" este un perete\n";
    return os;
}
