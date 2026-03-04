#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
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

            if (d[next] == -1) {     
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
    f(1);
    int index_B = 1;    // 끝 점 B
    for (int i = 2; i <= N; i++) {  
        if (d[index_B] < d[i]) {
            index_B = i;
        }
    }

    memset(d, -1, sizeof(d));
    f(index_B);
    int index_A = 1;    // 끝 점 A (A-B: 가장 긴 지름)
    for (int i = 2; i <= N; i++) {
        if (d[index_A] < d[i]) {
            index_A = i;
        }
    }

    memset(d, -1, sizeof(d));
    f(index_A); 
    int index_B2 = 0;   // 2번째로 먼 점
    for (int i = 1; i <= N; i++) {
        if (i == index_B) continue; // 가장 먼점은 패스함
        if (d[index_B2] < d[i]) {
            index_B2 = i;   
        }
    }
    int max1 = d[index_B2]; // A-B2 거리

    memset(d, -1, sizeof(d));
    f(index_B);
    int index_A2 = 0;   // 2번째로 먼 점
    for (int i = 1; i <= N; i++) {
        if (i == index_A) continue; // 가장 먼점은 패스함
        if (d[index_A2] < d[i]) {
            index_A2 = i;
        }
    }
    int max2 = d[index_A2];

    int result = max(max1, max2);
    cout << result;
}