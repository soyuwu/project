#include "../include/Square.h"

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
