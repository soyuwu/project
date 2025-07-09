
#include <iostream>
using namespace std;
#define M 100

struct NODE
{
    int key;
    NODE *pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE *CreateNode(int x)
{
    NODE *p;
    p = new NODE;
    p->key = x;
    p->pNext = NULL;
    return p;
}
void AddTail(NODE *&head, int x)
{
    NODE *p = CreateNode(x);
    if (head == NULL)
        head = p;
    else
    {
        NODE *i = head;
        while (i->pNext != NULL)
        {
            i = i->pNext;
        }
        i->pNext = p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }
void CreateHashTable(HASHTABLE &H, int &numbucket)
{
    int x, h;
    cin >> numbucket;
    for (int i = 0; i < M; i++)
        H[i] = NULL;
    while (true)
    {
        cin >> x;
        if (x == -1)
            return;
        int vt = HF(numbucket, x);
        AddTail(H[vt], x);
    }
}
void PrintList(NODE *H)
{
    if (H == NULL)
        return;
    while (H != NULL)
    {
        cout << " --> " << H->key;
        H = H->pNext;
    }
}
void Traverse(HASHTABLE H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
    {
        cout << i;
        PrintList(H[i]);
        cout << endl;
    }
}

int main()
{
    HASHTABLE H;
    int numbucket;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    return 0;
}