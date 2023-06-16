//
// Created by david on 6/16/2023.
//

#include "JocFactory.h"

Interfata_joc *JocFactory::creazaJoc(const std::string &tip) {

    if (tip == "EndlessMaze") {
        return new EndlessMaze();
    } else if (tip == "GuessNumber") {

        std::cout<<"Introduceti tipul de numar: int, char sau float: ";
        std::string tip_numar;
        std::cin>>tip_numar;
        if(tip_numar == "int")
            return new GuessTheNumber<int>(10);
        else if(tip_numar == "char")
            return new GuessTheNumber<char>(10);
        else if(tip_numar == "float")
            return new GuessTheNumber<float>(10);
    } else if (tip == "FallingBlocks") {
        return new FallingBlocks();
    } else if (tip == "TicTacToe") {
        return new TicTacToe();
    } else {
        return nullptr; // Or handle the case where the tip does not match any known game.
    }
    return nullptr;
}
