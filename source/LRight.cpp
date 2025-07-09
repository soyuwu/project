#include "../include/LRight.h"

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
