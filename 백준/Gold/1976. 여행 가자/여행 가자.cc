#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int SIZE = 201;
int parent[SIZE];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int rootX = find(x);    
    int rootY = find(y);
    // 루트 노드

    if (rootX == rootY) return;
    parent[rootY] = rootX;
}

bool isUnion(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    // 루트 노드

    if (rootX == rootY) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int c;
            cin >> c;
            if (c == 1) unite(i, j);
        }
    }
    int start;
    cin >> start;   // 출발점
    int root = find(start);
    for (int i = 1; i < m; i++) {
        int next;   // 다음 도시
        cin >> next;
        if (find(next) != root) {   // next의 루트가 현재 루트와 다름 
            cout << "NO";           // 연결이 끊긴 상태
            return 0;
        }
    }
    cout << "YES";
}