#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, B = 3, C = 2;
    cin >> N;
    vector<long long> v;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    long long res = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (v[i + 1] > v[i + 2]) {  // 2개씩 -> 3개씩
            cnt = min(v[i], v[i + 1] - v[i + 2]);
            v[i] -= cnt;
            v[i + 1] -= cnt;
            res += cnt * (B + C);
        }
        cnt = min(v[i], min(v[i + 1], v[i + 2]));   // 3개씩
        v[i] -= cnt;
        v[i + 1] -= cnt;
        v[i + 2] -= cnt;
        res += cnt * (B + 2 * C);

        cnt = min(v[i], v[i + 1]);  // 2개 씩
        v[i] -= cnt;
        v[i + 1] -= cnt;
        res += cnt * (B + C);

        res += v[i] * B;    // 1개씩
    }


    cout << res;
} 