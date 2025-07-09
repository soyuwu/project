#include "../include/ZLeft.h"

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
