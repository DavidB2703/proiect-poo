//
// Created by david on 5/22/2023.
//
#include <iostream>
#include "Interfata_joc.h"
#ifndef OOP_TICTACTOE_H
#define OOP_TICTACTOE_H


class TicTacToe: public Interfata_joc{
public:
    TicTacToe();

    void update() override;

    void render() override;

    void pollEvents() override {
        // No event polling in this simple game
    }

    void initializare_fereastra() override {
        // No window initialization in this simple game
    }

    bool running() override;

    void restartGame() override;

private:
    bool isRunning;
    std::vector<char> board;
    char currentPlayer;

    bool checkWin() const;

    bool isBoardFull() const;
};


#endif //OOP_TICTACTOE_H
