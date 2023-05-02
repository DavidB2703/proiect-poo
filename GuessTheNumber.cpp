//
// Created by david on 4/26/2023.
//

#include "GuessTheNumber.h"

[[maybe_unused]] GuessTheNumber::GuessTheNumber(int maxNumGuesses){
    srand(time(nullptr));
    numToGuess = rand() % 100 + 1;
    numGuesses = 0;
    this->maxNumGuesses = maxNumGuesses;
    gameOver = false;
    numGamesPlayed++;
}

void GuessTheNumber::update()
    {
        if (!gameOver && numGuesses >= maxNumGuesses) {
            std::cout << "You ran out of guesses! The number was " << numToGuess << std::endl;
            gameOver = true;
        }
        if (!gameOver) {
            std::cout << "Enter your guess: ";
            int guess;
            std::cin >> guess;
            numGuesses++;
            if (guess == numToGuess) {
                std::cout << "Congratulations! You guessed the number in " << numGuesses << " tries." << std::endl;
                gameOver = true;
            }
            else if (guess < numToGuess) {
                if (guess < 0)
                    throw eroare_GuessTheNumber("Numarul este intre 0 si 100, nu poti introduce numere negative ");
                else
                {std::cout << "Too low!" << std::endl;}
            }
            else {
                if (guess > 100)
                    throw eroare_GuessTheNumber("Numarul este intre 0 si 100, nu poti introduce numere mai mare decat 100 ");
                else
                {std::cout << "Too high!" << std::endl;}
            }
        }
}

void GuessTheNumber::afisare_nr_jocuri() {
    std::cout<<"Number of games played: "<< numGamesPlayed<<"\n";
}
