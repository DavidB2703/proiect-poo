//
// Created by david on 4/26/2023.
//

#include "GuessTheNumber.h"
#include "limits"
[[maybe_unused]] GuessTheNumber::GuessTheNumber(int maxNumGuesses){
    guesses=0;
    srand(time(nullptr));
    numToGuess = rand() % 100 + 1;
    numGuesses = 0;
    this->maxNumGuesses = maxNumGuesses;
    gameOver = false;
    numGamesPlayed++;
    this->stopsign = true;
    std::cout << "Press '0' to stop playing\n";
}

void GuessTheNumber::update()
    {
        guesses++;
        if (!gameOver && numGuesses >= maxNumGuesses) {
            std::cout << "You ran out of guesses! The number was " << numToGuess << std::endl;
            gameOver = true;
        }
        if (!gameOver) {
            std::cout<< "Enter your guess: "<<" "<<numToGuess;

            int guess;
            std::cin >> guess;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw eroare_GuessTheNumber("Trebuie sa introduci un numar");
            }

            numGuesses++;
            if (guess == numToGuess) {
                std::cout << "Congratulations! You guessed the number in " << numGuesses << " tries." << std::endl;
                gameOver = true;
            } else if (guess < numToGuess) {
                if (guess < 0)
                    throw eroare_GuessTheNumber("Numarul este intre 0 si 100, nu poti introduce numere negative ");
                else { std::cout << "Too low!" << std::endl; }
            } else {
                if (guess > 100)
                    throw eroare_GuessTheNumber(
                            "Numarul este intre 0 si 100, nu poti introduce numere mai mare decat 100 ");
                else { std::cout << "Too high!" << std::endl; }
            }
            if (guess == 0)
                stopsign = false;
            else
                stopsign= true;
        }
        else{
            this->restartGame();
            }

}

void GuessTheNumber::afisare_nr_jocuri() {
    std::cout<<"Number of games played: "<< numGamesPlayed<<"\n";
}


bool GuessTheNumber::running() {
    return this -> stopsign;
}

GuessTheNumber::~GuessTheNumber() {

}

void GuessTheNumber::initializare_fereastra() {

    this->restartGame();

}

void GuessTheNumber::restartGame() {
    guesses=0;
    srand(time(nullptr));
    numToGuess = rand() % 100 + 1;
    numGuesses = 0;
    gameOver = false;
    numGamesPlayed++;
    this->stopsign = true;
    std::cout << "Press '0' to stop playing\n";
}

