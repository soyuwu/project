#pragma once
#include "Piece.h"

class I : public Piece{
public:
    I();
    void Rotate() override;
    pair<int,int> returnbegin() override;
};
//
