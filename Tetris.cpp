#include "Tetris.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "I.h"
#include "LLeft.h"
#include "LRight.h"
#include "Square.h"
#include "ZLeft.h"
#include "ZRight.h"
#include "T.h"
using namespace std;

Tetris::Tetris() {
    memset(board, '.', sizeof(board));
    n = 0;
}
void Tetris::PrintBoard() {
    cout << "  0 1 2 3 4 5 6 7 8 9\n";
    for(int i = 0; i < 8; i++) {
        cout << i << " ";
        for(int j = 0; j < 10; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void Tetris::start() {
    srand(time(0));
    Piece* p;
    int numbrick = rand() % 16 + 20;
    int i, j;
    while(numbrick) {
        i = rand() % 8;
        j = rand() % 10;
        if(board[i][j] == '.') {
            board[i][j] = 'x';
            numbrick--;
        }
    }
    while(n < 25) {
        cout << "Manh thu " << n + 1 << " !\n";
        PrintBoard();
        n++;
        int r = rand() % 7;
        if(r == 0) p = new I;
        else if(r == 1) p = new LLeft;
        else if(r == 2) p = new LRight;
        else if(r == 3) p = new Square;
        else if(r == 4) p = new ZLeft;
        else if(r == 5) p = new ZRight;
        else p = new T;
        cout << "Manh hien tai: \n";
        p->Out();
        cout << "-------------\n";
        cout << "1. Xoay manh\n";
        cout << "2. Dat manh\n";
        cout << "3. Bo manh\n";
        cout << "-------------\n";
        cout << "Chon thao tac: ";
        int choice; cin >> choice;
        while(choice < 1 || choice > 3) {
            cout << "Vui long nhap lai: "; cin >> choice;
        }
        while(choice == 1) {
            p->Rotate();
            system("cls");
            PrintBoard();
            cout << "Manh sau khi xoay!\n";
            p->Out();
            cout << "-------------\n";
            cout << "1. Xoay manh\n";
            cout << "2. Dat manh\n";
            cout << "3. Bo manh\n";
            cout << "-------------\n";
            cout << "Chon thao tac: ";
            cin >> choice;
            while(choice < 1 || choice > 3) {
                cout << "Vui long nhap lai: "; cin >> choice;
            }
        }
        if(choice == 2) {
            int x, y;
            cout << "Nhap diem bat dau:\n";
            cout << "Nhap so dong: "; cin >> x;
            cout << "Nhap so cot: "; cin >> y;
            while(!check(p, x, y)) {
                cout << "Vi tri khong hop le. Vui long nhap lai!\n";
                cout << "Nhap hoanh do: "; cin >> x;
                cout << "Nhap tung do: "; cin >> y;
            }
            push(p, x, y);
            system("cls");
        } else if(choice == 3) {
            system("cls");
            continue;
        }
        delete p;
    }
    cout << "Tro choi ket thuc!\n";
}
int Tetris::score() {
    int mark = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 10; j++) {
            if(board[i][j] == 'x') mark++;
        }
    }
    int col = 0;
    int cnt = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[j][i] != 'x') continue;
            else cnt++;
        }
        if(cnt == 8) col++;
        cnt = 0;
    }
    return mark + 4 * col;
}
void Tetris::push(Piece* p, int x, int y) {
    char cop[4][4];
    pair<int,int> start = p->returnbegin();
    p->Copy(cop);
    bool first = true;
    for(int i = 0; i < 4; i++) {
        if(i == 0) {
            for(int j = start.second; j < 4; j++) {
                if(cop[i][j] == 'x') {
                    board[x + i - start.first][y + j - start.second] = 'x';
                }
            }
            continue;
        }
        for(int j = 0; j < 4; j++) {
            if(cop[i][j] == 'x') {
                board[x + i - start.first][y + j - start.second] = 'x';
            }
        }
    }
}
bool Tetris::check(Piece* p, int x, int y) {
    if(board[x][y] == 'x') return false;
    char cop[4][4];
    pair<int,int> start = p->returnbegin();
    p->Copy(cop);
    for(int i = 0; i < 4; i++) {
        if(i == 0) {
            for(int j = start.second; j < 4; j++) {
                if(cop[i][j] == 'x' && board[x + i][y + j] == 'x') return false;
            }
            continue;
        }
        for(int j = 0; j < 4; j++) {
            if(cop[i][j] == 'x') {
                if(x + i - start.first > 7 || x + i - start.first < 0 || y + j - start.second > 9 || y + j - start.second < 0) return false;
            }
            if(cop[i][j] == 'x' && board[x + i - start.first][y + j - start.second] == 'x') return false;
        }
    }
    return true;
}
