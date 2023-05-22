#include "Meniu.h"
#include "Tabla.h"
#include "EndlessMaze.h"
#include "FallingBlocks.h"
#include "GuessTheNumber.h"
#include "Casuta_Joc.h"






class TicTacToe : public Interfata_joc {
public:
    TicTacToe() : isRunning(true), currentPlayer('X') {
        board = std::vector<char>(9, ' ');
    }

    void update() override {
        Interfata_joc::update();
        int move;
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        std::cin >> move;

        // Convert move from 1-based to 0-based index
        move--;

        if (move < 0 || move >= 9 || board[move] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            return;
        }

        board[move] = currentPlayer;

        if (checkWin()) {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            isRunning = false;
        } else if (isBoardFull()) {
            std::cout << "It's a draw!" << std::endl;
            isRunning = false;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    void render() override {
        std::cout << std::endl;
        std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
        std::cout << "-----------" << std::endl;
        std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
        std::cout << "-----------" << std::endl;
        std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
        std::cout << std::endl;
    }

    void pollEvents() override {
        // No event polling in this simple game
    }

    void initializare_fereastra() override {
        // No window initialization in this simple game
    }

    bool running() override {
        return isRunning;
    }

    void restartGame() override {
        board = std::vector<char>(9, ' ');
        currentPlayer = 'X';
        isRunning = true;
    }

private:
    bool isRunning;
    std::vector<char> board;
    char currentPlayer;

    bool checkWin() const {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i + 6]) {
                return true;
            }
        }

        // Check columns
        for (int i = 0; i < 9; i += 3) {
            if (board[i] != ' ' && board[i] == board[i + 1] && board[i] == board[i + 2]) {
                return true;
            }
        }

        // Check diagonals
        if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8]) {
            return true;
        }
        if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6]) {
            return true;
        }

        return false;
    }

    bool isBoardFull() const {
        for (const char& cell : board) {
            if (cell == ' ') {
                return false;
            }
        }
        return true;
    }
};


int Tabla::ct_tabla=0;
int FallingBlocks:: numar_inamici=0;
int GuessTheNumber::numGamesPlayed = 0;
float Casuta_Joc::x_scale = 300;
float const Meniu::sceneHeigh = 900.f;
int Tabla::numar_mutari=0;
int main()
{
    srand(time(nullptr));
    //creare casute care vor aparea in meniu
    auto* EndlessMaze = new Casuta_Joc("EndlessMaze");
    auto* FallingBlocks = new Casuta_Joc("FallingBlocks");
    auto* GuessTheNumber = new Casuta_Joc("GuessNumber");
    auto* TicTacToe = new Casuta_Joc("TicTacToe");

    Interfata_joc* joc0;
    Interfata_joc* joc1;
    Interfata_joc* joc2;
    Interfata_joc* joc3;

    joc0 = new class EndlessMaze();
    joc1 = new class FallingBlocks();
    joc2 = new class GuessTheNumber(10);
    joc3 = new class TicTacToe();

    Meniu meniu;

    meniu.addCasuta(EndlessMaze);
    meniu.addCasuta(FallingBlocks);
    meniu.addCasuta(GuessTheNumber);
    meniu.addCasuta(TicTacToe);
    meniu.initializare_casute();

    meniu.addJoc(joc0);
    meniu.addJoc(joc1);
    meniu.addJoc(joc2);
    meniu.addJoc(joc3);

    while(meniu.running())
    {
        meniu.update();
        meniu.render();
    }


}

