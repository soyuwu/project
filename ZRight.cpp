#include "ZRight.h"

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
