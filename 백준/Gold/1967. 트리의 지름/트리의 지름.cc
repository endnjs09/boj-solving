#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int SIZE = 100001;
vector<pair<int, int>> adj[SIZE];
int d[SIZE];

void f(int start) {
    
    queue<pair<int, int>> q;
    q.push({ start, 0 });

    d[start] = 0;

    while (!q.empty()) {
        int current = q.front().first;  
        int dist = q.front().second;
        q.pop();

        for (auto& n : adj[current]) {
            int next = n.first;
            int next_d = dist + n.second;

            if (d[next] == -1) {     // 방문 안했으면
                d[next] = next_d;
                q.push({ next, next_d });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    memset(d, -1, sizeof(d));
    f(1);   // 1번에서 가장 멀리 떨어진 거 찾기
    
    int max_index = 1;
    for (int i = 2; i <= N; i++) {
        if (d[max_index] < d[i])
            max_index = i;
    }

    memset(d, -1, sizeof(d));
    f(max_index);

    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = max(result, d[i]);
    }

    cout << result;
}