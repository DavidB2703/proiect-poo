#include <limits>
#include "Interfata_joc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class eroare_GuessTheNumber : public eroare_aplicatie {
public:
    explicit eroare_GuessTheNumber(const std::string& mesaj) :
            eroare_aplicatie( mesaj) {}
};
const float MAX = 2147483647;
template<typename T>
class GuessTheNumber : public Interfata_joc {
private:
    int guesses;
    T numToGuess;
    int numGuesses;
    int maxNumGuesses;
    bool gameOver;
    bool stopsign = true;
    static int numGamesPlayed;

public:
    explicit GuessTheNumber(int maxNumGuesses);
    void update() override;
    void render() override {};
    void pollEvents() override {};
    bool running() override;
    void initializare_fereastra() override;
    static void afisare_nr_jocuri();
    void restartGame() override;

    ~GuessTheNumber() override;
};

template<typename T>
int GuessTheNumber<T>::numGamesPlayed = 0;

template<typename T>
GuessTheNumber<T>::GuessTheNumber(int maxNumGuesses) {
    guesses = 0;
    srand(time(nullptr));
    if constexpr (std::is_same_v<T, int>) {
        numToGuess = rand() % 100 + 1;
    } else if constexpr (std::is_same_v<T, char>) {
        numToGuess = 'a' + rand() % 26;
    } else if constexpr (std::is_same_v<T, float>) {
        int randomNumber = std::rand() % 100; // Generarea unui număr întreg între 0 și 99
        double randomReal = static_cast<double>(randomNumber) / 100.0; // Transformarea într-un număr real cu 2 zecimale
        numToGuess = randomReal;
    }
    numGuesses = 0;
    this->maxNumGuesses = maxNumGuesses;
    gameOver = false;
    numGamesPlayed++;
    this->stopsign = true;
}

template<typename T>
void GuessTheNumber<T>::update() {
    guesses++;
    if (!gameOver && numGuesses >= maxNumGuesses) {
        std::cout << "You ran out of guesses! The ";
        if constexpr (std::is_same_v<T, int>) {
            std::cout << "number was ";
        } else if constexpr (std::is_same_v<T, char>) {
            std::cout << "letter was ";
        } else if constexpr (std::is_same_v<T, float>) {
            std::cout << "number was ";
        }
        std::cout << numToGuess << std::endl;
        gameOver = true;
    }
    if (!gameOver) {
        std::cout << "Enter ";
        if constexpr (std::is_same_v<T, int>) {
            std::cout << "an integer number between 1 and 100";
        } else if constexpr (std::is_same_v<T, char>) {
            std::cout << "a character between 'a' and 'z'";
        } else if constexpr (std::is_same_v<T, float>) {
            std::cout << "a floating-point number between 0 and 1 with 2 decimal places ";
        }
        std::cout << "\nPress '0' to stop playing\n";
        std::cout << "Enter your guess: ";

        T guess;
        std::cin >> guess;

        if (guess == 0 or guess == '0') {
            stopsign = false;
            return;
        }

        if (guess == numToGuess) {
            std::cout << "Congratulations! You guessed the ";
            if constexpr (std::is_same_v<T, int>) {
                std::cout << "number";
            } else if constexpr (std::is_same_v<T, char>) {
                std::cout << "letter";
            } else if constexpr (std::is_same_v<T, float>) {
                std::cout << "number";
            }
            std::cout << " in " << numGuesses << " tries." << std::endl;
            gameOver = true;
        } else if (guess < numToGuess) {
            std::cout << "Too low!" << std::endl;
        } else {
            std::cout << "Too high!" << std::endl;
        }
        numGuesses++;
    } else {
        this->restartGame();
    }
}

template<typename T>
void GuessTheNumber<T>::afisare_nr_jocuri() {
    std::cout << "Number of games played: " << numGamesPlayed - 2 << "\n";
}

template<typename T>
bool GuessTheNumber<T>::running() {
    return this->stopsign;
}

template<typename T>
GuessTheNumber<T>::~GuessTheNumber() {}

template<typename T>
void GuessTheNumber<T>::initializare_fereastra() {
    this->restartGame();
}

template<typename T>
void GuessTheNumber<T>::restartGame() {
    guesses = 0;
    srand(time(nullptr));
    if constexpr (std::is_same_v<T, int>) {
        numToGuess = rand() % 100 + 1;
    } else if constexpr (std::is_same_v<T, char>) {
        numToGuess = 'a' + rand() % 26;
    } else if constexpr (std::is_same_v<T, float>) {
        //float with 2 zecimal places
        int randomNumber = std::rand() % 100; // Generarea unui număr întreg între 0 și 99
        double randomReal = static_cast<double>(randomNumber) / 100.0; // Transformarea într-un număr real cu 2 zecimale
        numToGuess = randomReal;
    }
    numGuesses = 0;
    gameOver = false;
    numGamesPlayed++;
    this->stopsign = true;
}
