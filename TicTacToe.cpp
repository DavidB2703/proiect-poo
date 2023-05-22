//
// Created by david on 5/22/2023.
//

#include "TicTacToe.h"

void TicTacToe::update() {
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

void TicTacToe::render() {
    std::cout << std::endl;
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
    std::cout << std::endl;
}

bool TicTacToe::running() {
    return isRunning;
}

void TicTacToe::restartGame() {
    board = std::vector<char>(9, ' ');
    currentPlayer = 'X';
    isRunning = true;
}

bool TicTacToe::checkWin() const {
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

bool TicTacToe::isBoardFull() const {
    for (const char& cell : board) {
        if (cell == ' ') {
            return false;
        }
    }
    return true;
}

TicTacToe::TicTacToe() : isRunning(true), currentPlayer('X') {
    board = std::vector<char>(9, ' ');
}
