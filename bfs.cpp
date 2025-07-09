#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX]; // danh sách kề
bool visited[MAX];
int truoc[MAX]; // lưu đỉnh trước đó

void BFS(int s, int e) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    truoc[s] = -1; // đỉnh bắt đầu không có đỉnh trước

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                truoc[v] = u;
                q.push(v);
                if (v == e) return; // tìm thấy E, dừng
            }
        }
    }
}

void TruyVetDuongDi(int s, int e) {
    if (!visited[e]) {
        cout << "Khong co duong di tu " << s << " den " << e << endl;
        return;
    }

    stack<int> path;
    for (int v = e; v != -1; v = truoc[v])
        path.push(v);

    cout << "Duong di tu " << s << " den " << e << ": ";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

int main() {
    int n, m; // số đỉnh, số cạnh
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    cout << "Nhap cac canh (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // nếu là đồ thị vô hướng
    }

    int s, e;
    cout << "Nhap dinh bat dau va ket thuc: ";
    cin >> s >> e;

    BFS(s, e);
    TruyVetDuongDi(s, e);

    return 0;
}
