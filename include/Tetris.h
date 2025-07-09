#pragma once
#include "Piece.h"

class Tetris{
private:
    char board[8][10];
    int n;
public:
    Tetris();
    void push(Piece* p, int x, int y);
    bool check(Piece* p, int x, int y);
    void start();
    int score();
    void PrintBoard();
};
