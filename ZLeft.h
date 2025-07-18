#pragma once
#include "Piece.h"

class ZLeft : public Piece{
public:
    ZLeft();
    void Rotate() override;
    pair<int,int> returnbegin() override;
};
