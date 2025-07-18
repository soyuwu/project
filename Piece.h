#pragma once
#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

class Piece
{
protected:
    char p[4][4];
    int status;

public:
    Piece();
    virtual pair<int, int> returnbegin() = 0;
    void Out();
    virtual void Rotate() = 0;
    void Copy(char a[4][4]);
    virtual ~Piece() {}
};

class I : public Piece
{
public:
    I();
    void Rotate() override;
    pair<int, int> returnbegin() override;
};

class Square : public Piece
{
public:
    Square();
    void Rotate() override;
    pair<int, int> returnbegin() override;
};

class LRight : public Piece
{
public:
    LRight();
    void Rotate() override;
    pair<int, int> returnbegin() override;
};

class LLeft : public Piece
{
public:
    LLeft();
    void Rotate() override;
    pair<int, int> returnbegin() override;
};

class T : public Piece
{
public:
    T();
    void Rotate() override;
    pair<int, int> returnbegin() override;
};

class ZLeft : public Piece
{
public:
    ZLeft();
    void Rotate() override;
    pair<int, int> returnbegin() override;
};

class ZRight : public Piece
{
public:
    ZRight();
    void Rotate() override;
    pair<int, int> returnbegin() override;
};
