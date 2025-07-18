#include "I.h"

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
