#pragma once
#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

class Piece{
protected:
    char p[4][4];
    int status;
public:
    Piece();
    virtual pair<int,int> returnbegin() = 0;
    void Out();
    virtual void Rotate() = 0;
    void Copy(char a[4][4]);
    virtual ~Piece() {}
};
