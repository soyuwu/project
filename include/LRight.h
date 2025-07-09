#pragma once
#include "Piece.h"

class LRight : public Piece{
public:
    LRight();
    void Rotate() override;
    pair<int,int> returnbegin() override;
};
