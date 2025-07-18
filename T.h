#pragma once
#include "Piece.h"

class T : public Piece{
public:
    T();
    void Rotate() override;
    pair<int,int> returnbegin() override;
};
