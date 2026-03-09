#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int SIZE = 100001;
vector<int> adj[SIZE];
bool visited[SIZE];
int depth[SIZE], p[SIZE][18];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : adj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                depth[next] = depth[curr] + 1;
                p[next][0] = curr;  // next의 1칸(2^0) 위 노드 = curr
                q.push(next);
            }
        }
    }
}

int f(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    int tmp = depth[y] - depth[x];

    for (int k = 0; k < 18; k++) {
        if (tmp & (1 << k))
            y = p[y][k];
    }
    if (x == y) return x;   
    else {
        for (int k = 17; k >= 0; k--) {
            if (p[x][k] != p[y][k]) {
                x = p[x][k];
                y = p[y][k];
            }
        }
        return p[x][0];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1); 
    for (int k = 1; k < 18; k++) {  // 모든 노드에 대해 2^k 칸 위 노드 기록
        for (int node = 1; node <= N; node++) {
            p[node][k] = p[p[node][k - 1]][k - 1];
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cout << f(u, v) << '\n';
    }
}