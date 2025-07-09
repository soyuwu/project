#include <iostream>
#include <vector>
using namespace std;

// Hàm nhập danh sách cạnh và xây dựng ma trận kề
void Input(vector<vector<int>>& G, int v, int e) {
    if(v==0){
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                cout << 0 << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < e; ++i) {
        int u, w;
        cin >> u >> w;
        G[u][w] = 1; // Đánh dấu có cạnh từ u đến w
        G[w][u] = 1; // Vì đồ thị vô hướng
    }

    // Xuất ma trận kề
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
	int v, e; // v là số đỉnh, e là số cạnh
	cin >> e >> v;
	vector<vector<int>> G(v, vector<int>(v, 0));
	Input(G, v, e);
	return 0;
}
