
#include <iostream>
#include <string>

using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE
{
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, Giá trị khác: Node đang tồn tại giá trị
    int key;
};

struct HASHTABLE
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i)
{
    int h = HF(ht, key);
    return (h + i) % ht.M;
}
void Insert(HASHTABLE &a, int x)
{

    if (double(a.n + 1) / a.M > 0.7)
        return;

    int vt = HF(a,x);
    int i = 0;

    while (true)
    {

        if (a.table[vt].flag == EMPTY || a.table[vt].flag == DELETED)
        {
            a.table[vt].key = x;
            a.table[vt].flag = OCCUPIED;
            a.n++;
            return;
        }
        if (a.table[vt].flag == OCCUPIED && a.table[vt].key == x)
            return;
        else
            vt = HF_LinearProbing(a, x, ++i);
    }
}
void Delete(HASHTABLE &a, int x) {
    int vt = HF(a, x);
    int i = 0;

    while (true) {
        if (a.table[vt].flag == EMPTY) {
            return;
        }

        if (a.table[vt].flag == OCCUPIED && a.table[vt].key == x) {
            a.table[vt].flag = DELETED;
            a.n--; 
            return;
        }

        vt = HF_LinearProbing(a, x, ++i);
    }
}
void CreateHashTable(HASHTABLE &H)
{

    cin >> H.M;
    H.n = 0;

    H.table = new NODE[H.M];

    for (int i = 0; i < H.M; i++)
        H.table[i].flag = EMPTY;
    int x;
    cin>>x;
    int i=1;
    while (i<=x)
    {
        int a,b;
        cin>>a>>b;
        if(a==1){
            Insert(H, b);
        }
        else{
            Delete(H, b);
        }
        i++;
    }
}
void DeleteHashtable(HASHTABLE &ht)
{
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}
void Traverse(HASHTABLE H)
{
    for (int i = 0; i < H.M; i++)
    {
        cout << i<<" --> ";
        if(H.table[i].flag==EMPTY) cout<<"EMPTY";
        else if(H.table[i].flag==DELETED)   cout<<"DELETED";
        else    cout<<H.table[i].key;
        cout << endl;
    }
}
int main()
{
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}