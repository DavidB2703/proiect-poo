//
// Created by david on 4/26/2023.
//

#ifndef OOP_GUESSTHENUMBER_H
#define OOP_GUESSTHENUMBER_H

#include "Interfata_joc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class eroare_GuessTheNumber : public eroare_aplicatie {
public:
    explicit eroare_GuessTheNumber(const std::string& mesaj) :
            eroare_aplicatie( mesaj) {}
};

class GuessTheNumber : public Interfata_joc {
private:
    int numToGuess;
    int numGuesses;
    int maxNumGuesses;
    bool gameOver;

    static int numGamesPlayed;

public:
    [[maybe_unused]] explicit GuessTheNumber(int maxNumGuesses);

    void update() override;

    void render() override {
        // not needed for this game
    }

    void pollEvents() override {
        // not needed for this game
    }
    bool running() override{
        // not needed for this game
        return false;
    }

    static void afisare_nr_jocuri();
};



#endif //OOP_GUESSTHENUMBER_H
