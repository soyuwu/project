#include <iostream>
#include <string.h>
#include <list>
using namespace std;
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1
#define MAXTABLESIZE 10000
const int TableSize = 10000;
struct user{
    string username;
    list<string> pass;
};
struct node{
    int flag;
    user key;
};
typedef node* hashtable[MAXTABLESIZE];
int HF(hashtable ht, string username, int num){
    int s=0;
    for(int i=0; i<username.length(); i++){
        s+=37*username[i]+i;
    }
    return s%num;
}
int HF_LinearProbing(int h, int i, int num){
    return (h+i)%num;
}
void Insert(hashtable& H, string user, string pass, int num) {
    int q = HF(H, user, num);
    int i = 1;
    while (i < num && H[i]->flag == OCCUPIED) {
        if (H[i]->key.username == user) break;
        q = HF_LinearProbing(q, i++,num);
    }
    if(i==num) return;
    H[i]->key.username = user;
    H[i]->key.pass.push_back(pass);
    H[i]->flag = OCCUPIED;
}
void CreateHash(hashtable &H, int num){
    new hashtable[num];
    for(int i=0; i<num;i++){
        H[i]->flag=EMPTY;
    }
    string name, pass;
    for(int i=0; i<num; i++){
        cin>>name>>pass;
        Insert(H,name,pass,num);
        
    }
}










int main() {
	hashtable H;
	int CurrentSize;
	int n, m;
	cin >> n >> m;

	CreateHash(H, n);
	//OutPassword(H, CurrentSize, m);

	return 0;
}

