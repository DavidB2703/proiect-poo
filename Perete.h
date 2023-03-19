//
// Created by david on 3/12/2023.
//

#ifndef OOP_PERETE_H
#define OOP_PERETE_H
#include <iostream>

class Perete{
private:
    int coor_x, coor_y;
    ///functii private

public:

    ///Functii publice


    ///Constructori/Deconstructori/Operator=/Operator<<

    explicit Perete( int coor_x_=0, int coor_y_=0);
    Perete( const Perete& other );
    Perete& operator=(const Perete& other);
    ~Perete();
    friend std :: ostream& operator<<(std::ostream& os, const Perete& perete);

};


#endif //OOP_PERETE_H
