#include <iostream>
#include <vector>
using namespace std;
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1
struct NODE
{
    int flag;
    string key;
    vector<string> data;
};
struct HASHTABLE
{
    int M;
    NODE *table;
};
int HF(HASHTABLE ht, string username)
{
    int s = 0;
    for (int i = 0; i < username.length(); i++)
        s += 37 * username[i] + i;
    return s % ht.M;
}
int reHF(HASHTABLE H, string key, int k)
{
    return (HF(H, key) + k) % H.M;
}
void Insert(HASHTABLE &H, string key, string data)
{
    int i = HF(H, key);
    int k = 1;
    while (true)
    {
        if (H.table[i].flag == EMPTY || H.table[i].flag == DELETED)
        {
            H.table[i].flag = OCCUPIED;
            H.table[i].key = key;
            H.table[i].data.push_back(data);
            return;
        }
        else if (H.table[i].flag == OCCUPIED && H.table[i].key == key)
        {
            H.table[i].data.push_back(data);
            return;
        }
        else
        {
            if (k == H.M)
                return;
            i = reHF(H, key, k);
            k++;
        }
    }
}
int Search(HASHTABLE H, string key)
{
    int i = HF(H, key);
    int k = 1;
    while (true)
    {
        if (H.table[i].flag == EMPTY || H.table[i].flag == DELETED)
            return -1;
        else if (H.table[i].flag == OCCUPIED && H.table[i].key == key)
            return i;
        else
        {
            if (k == H.M)
                return -1;
            i = reHF(H, key, k);
            k++;
        }
    }
}
void CreateHashTable(HASHTABLE &H, int n)
{
    H.M = n;
    H.table = new NODE[H.M];
    for (int i = 0; i < n; i++)
    {
        H.table[i].flag = EMPTY;
    }
    string key, data;
    while (n--)
    {
        cin >> key >> data;
        Insert(H, key, data);
    }
}
void Find(HASHTABLE H, int q)
{
    string key;
    int i;
    while (q--)
    {
        cin >> key;
        i = Search(H, key);
        if (i == -1)
            cout << "Unregistered User.\n";
        else
        {
            for (int index = 0; index < H.table[i].data.size(); index++)
            {
                cout << H.table[i].data[index] << " ";
            }
            cout << endl;
        }
    }
}
void DeleteHashtable(HASHTABLE &ht)
{
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}
int main()
{
    HASHTABLE H;
    int n, q;
    cin >> n >> q;
    CreateHashTable(H, n);
    Find(H, q);
    DeleteHashtable(H);
}