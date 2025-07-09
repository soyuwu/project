#pragma once
#include "Piece.h"

class Square : public Piece{
public:
    Square();
    void Rotate() override;
    pair<int,int> returnbegin() override;
};
