#pragma once
#include "Piece.cpp"

class LLeft : public Piece{
public:
    LLeft();
    void Rotate() override;
    pair<int,int> returnbegin() override;
};
