#pragma once
#include "Piece.h"

class ZRight : public Piece{
public:
    ZRight();
    void Rotate() override;
    pair<int,int> returnbegin() override;
};
