#include "../include/Piece.h"

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
