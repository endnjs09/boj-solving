#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct Point {
    int x, y, cnt, hm, day;
};

bool visited[1001][1001][11][2];    // 낮: 0, 밤: 1   

void bfs(vector<vector<int>>& v, int x, int y, int k) {
    queue<Point> q;
    q.push({ 0, 0, 1, 0, 0 });
    visited[0][0][0][0] = true;


    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        bool isDay = (curr.day == 0);

        if (curr.x == x - 1 && curr.y == y - 1) {       // 목적지에 도달
            cout << curr.cnt;                // 답 출력
            return;
        }

        for (int i = 0; i < 4; i++) {   // 현재 위치에서 방향 벡터 더함
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < x && ny >= 0 && ny < y) {

                if (v[nx][ny] == 0 && !visited[nx][ny][curr.hm][!isDay]) {   // 길을 만남
                    visited[nx][ny][curr.hm][!isDay] = true;         // 방문 체크
                    q.push({ nx, ny, curr.cnt + 1, curr.hm, !curr.day });       // 큐에 push (다음 칸으로)
                }
                else if (v[nx][ny] == 1 && curr.hm < k) {   // 벽을 만남 (부술 수 있음)

                    if (isDay) {    // 낮이면 부숨
                        if (!visited[nx][ny][curr.hm + 1][!isDay]) {
                            visited[nx][ny][curr.hm + 1][!isDay] = true;  // 방문 체크
                            q.push({ nx, ny, curr.cnt + 1, curr.hm + 1, !curr.day});  // 밤으로 변경
                        }
                    }
                    else {  // 밤이면 제자리
                        if (!visited[curr.x][curr.y][curr.hm][!isDay]) {
                            visited[curr.x][curr.y][curr.hm][!isDay] = true;
                            q.push({ curr.x, curr.y, curr.cnt + 1, curr.hm, !curr.day });
                        }
                    }

                }

            }

        }

    }

    cout << -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> adj(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++) {
            adj[i][j] = str[j] - '0';
        }
    }

    bfs(adj, N, M, K);
}