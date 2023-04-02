//
// Created by david on 3/12/2023.
//

#ifndef OOP_PERETE_H
#define OOP_PERETE_H
#include <iostream>
#include <ctime>
#include <cstdlib>

class Perete{
private:
    int coor_x=rand()%30, coor_y=rand()%40;
    ///functii private

public:

    ///Functii publice


    ///Constructori/Deconstructori/Operator=/Operator<<

    explicit Perete( int coor_x_, int coor_y_);
    Perete( const Perete& other );
    Perete& operator=(const Perete& other);
    ~Perete();
    friend std :: ostream& operator<<(std::ostream& os, const Perete& perete);

};


#endif //OOP_PERETE_H
