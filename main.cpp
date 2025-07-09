#include "Tetris.h"
#include <iostream>
using namespace std;

int main() {
    Tetris New;
    New.start();
    cout << "Diem so cua nguoi choi la: " << New.score() << endl;
    return 0;
}
