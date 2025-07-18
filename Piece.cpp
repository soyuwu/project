#include "Piece.h"

Piece::Piece() {
    memset(p, '.', sizeof(p));
}
void Piece::Out() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}
void Piece::Copy(char a[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            a[i][j] = p[i][j];
        }
    }
}

I::I() {
    memset(p, '.', sizeof(p));
    for(int i = 0; i < 4; i++) p[i][0] = 'x';
    status = 1;
}
void I::Rotate() {
    if(status == 1) {
        memset(p, '.', sizeof(p));
        for(int i = 0; i < 4; i++) p[0][i] = 'x';
        status = 2;
    } else if(status == 2) {
        memset(p, '.', sizeof(p));
        for(int i = 0; i < 4; i++) p[i][0] = 'x';
        status = 1;
    }
}
pair<int,int> I::returnbegin() {
    return {0,0};
}

Square::Square() {
    memset(p, '.', sizeof(p));
    p[0][0] = 'x';
    p[1][1] = 'x';
    p[1][0] = 'x';
    p[0][1] = 'x';
}
void Square::Rotate() { return; }
pair<int,int> Square::returnbegin() {
    return {0,0};
}

LRight::LRight() {
    memset(p, '.', sizeof(p));
    p[0][0] = 'x';
    p[1][0] = 'x';
    p[2][0] = 'x';
    p[2][1] = 'x';
    status = 1;
}
void LRight::Rotate() {
    if(status == 1) {
        memset(p, '.', sizeof(p));
        p[0][0] = 'x';
        p[0][1] = 'x';
        p[0][2] = 'x';
        p[1][0] = 'x';
        status = 2;
    } else if(status == 2) {
        memset(p, '.', sizeof(p));
        p[0][0] = 'x';
        p[0][1] = 'x';
        p[1][1] = 'x';
        p[2][1] = 'x';
        status = 3;
    } else if(status == 3) {
        memset(p, '.', sizeof(p));
        p[1][0] = 'x';
        p[1][1] = 'x';
        p[1][2] = 'x';
        p[0][2] = 'x';
        status = 4;
    } else {
        memset(p, '.', sizeof(p));
        p[0][0] = 'x';
        p[1][0] = 'x';
        p[2][0] = 'x';
        p[2][1] = 'x';
        status = 1;
    }
}
pair<int,int> LRight::returnbegin() {
    if(status == 1) return {0,0};
    if(status == 2) return {0,0};
    if(status == 3) return {0,0};
    if(status == 4) return {0,2};
    return {0,0};
}

LLeft::LLeft() {
    memset(p, '.', sizeof(p));
    p[0][1] = 'x';
    p[1][1] = 'x';
    p[2][0] = 'x';
    p[2][1] = 'x';
    status = 1;
}
void LLeft::Rotate() {
    if(status == 1) {
        memset(p, '.', sizeof(p));
        p[0][0] = 'x';
        p[1][1] = 'x';
        p[1][0] = 'x';
        p[1][2] = 'x';
        status = 2;
    } else if(status == 2) {
        memset(p, '.', sizeof(p));
        p[0][0] = 'x';
        p[0][1] = 'x';
        p[1][0] = 'x';
        p[2][0] = 'x';
        status = 3;
    } else if(status == 3) {
        memset(p, '.', sizeof(p));
        p[0][0] = 'x';
        p[0][1] = 'x';
        p[0][2] = 'x';
        p[1][2] = 'x';
        status = 4;
    } else {
        memset(p, '.', sizeof(p));
        p[0][1] = 'x';
        p[1][1] = 'x';
        p[2][0] = 'x';
        p[2][1] = 'x';
        status = 1;
    }
}
pair<int,int> LLeft::returnbegin() {
    if(status == 1) return {0,1};
    if(status == 2) return {0,0};
    if(status == 3) return {0,0};
    if(status == 4) return {0,0};
    return {0,0};
}

T::T() {
    memset(p, '.', sizeof(p));
    p[0][0] = 'x';
    p[0][1] = 'x';
    p[0][2] = 'x';
    p[1][1] = 'x';
    status = 1;
}
void T::Rotate() {
    if(status == 1) {
        memset(p, '.', sizeof(p));
        p[0][1] = 'x';
        p[1][1] = 'x';
        p[1][0] = 'x';
        p[2][1] = 'x';
        status = 2;
    } else if(status == 2) {
        memset(p, '.', sizeof(p));
        p[0][1] = 'x';
        p[1][1] = 'x';
        p[1][0] = 'x';
        p[1][2] = 'x';
        status = 3;
    } else if(status == 3) {
        memset(p, '.', sizeof(p));
        p[0][0] = 'x';
        p[1][1] = 'x';
        p[1][0] = 'x';
        p[2][0] = 'x';
        status = 4;
    } else if(status == 4) {
        memset(p, '.', sizeof(p));
        p[0][0] = 'x';
        p[0][1] = 'x';
        p[0][2] = 'x';
        p[1][1] = 'x';
        status = 1;
    }
}
pair<int,int> T::returnbegin() {
    if(status == 1) return {0,0};
    if(status == 2) return {0,1};
    if(status == 3) return {0,1};
    if(status == 4) return {0,0};
    return {0,0};
}

ZLeft::ZLeft() {
    memset(p, '.', sizeof(p));
    p[1][0] = 'x';
    p[1][1] = 'x';
    p[0][1] = 'x';
    p[0][2] = 'x';
    status = 1;
}
void ZLeft::Rotate() {
    if(status == 1) {
        memset(p, '.', sizeof(p));
        p[0][0] = 'x';
        p[1][1] = 'x';
        p[1][0] = 'x';
        p[2][1] = 'x';
        status = 2;
    } else if(status == 2) {
        memset(p, '.', sizeof(p));
        p[1][0] = 'x';
        p[1][1] = 'x';
        p[0][1] = 'x';
        p[0][2] = 'x';
        status = 1;
    }
}
pair<int,int> ZLeft::returnbegin() {
    if(status == 1) return {0,1};
    if(status == 2) return {0,0};
    return {0,0};
}

ZRight::ZRight() {
    memset(p, '.', sizeof(p));
    p[0][0] = 'x';
    p[1][1] = 'x';
    p[0][1] = 'x';
    p[1][2] = 'x';
    status = 1;
}
void ZRight::Rotate() {
    if(status == 1) {
        memset(p, '.', sizeof(p));
        p[0][1] = 'x';
        p[1][1] = 'x';
        p[1][0] = 'x';
        p[2][0] = 'x';
        status = 2;
    } else if(status == 2) {
        memset(p, '.', sizeof(p));
        p[0][0] = 'x';
        p[1][1] = 'x';
        p[0][1] = 'x';
        p[1][2] = 'x';
        status = 1;
    }
}
pair<int,int> ZRight::returnbegin() {
    if(status == 1) return {0,0};
    if(status == 2) return {0,1};
    return {0,0};
}


