//
// Created by david on 6/16/2023.
//

#ifndef OOP_JOCFACTORY_H
#define OOP_JOCFACTORY_H
#include "Interfata_joc.h"
#include "GuessTheNumber.h"
#include "EndlessMaze.h"
#include "FallingBlocks.h"
#include "TicTacToe.h"


class JocFactory {
public:
    static Interfata_joc* creazaJoc(const std::string& tip);
};


#endif //OOP_JOCFACTORY_H
