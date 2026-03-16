#include <iostream>
using namespace std;

int arr[1001][1001];
int x, y;   // 최솟값 위치
int R, C;

void f(int x, int y) {  // R, C 둘다 짝수
    for (int i = 0; i < (x / 2) * 2; i += 2) {
        for (int j = 0; j < C - 1; j++) cout << 'R';
        cout << "D";
        for (int j = 0; j < C - 1; j++) cout << 'L';
        cout << 'D';
    }
    bool flag = 0;  // 윗줄에 있는 상태
    for (int j = 0; j < C; j++) {
        if (j == y) {   // target 열 위치에 있음
            if (j < C - 1) cout << 'R'; // 끝이 아니면 오른쪽으로
        }
        else {  // target 열에 위치하지 않음
            if (!flag) {    // target과 같은 행(위)
                flag = 1;
                cout << "D";
            }
            else {          // target과 다른 행(아래)
                flag = 0;
                cout << "U";
            }

            if (j < C - 1) cout << 'R'; // 끝이 아니면 오른쪽으로
        }
    }
    for (int i = (x / 2) * 2 + 2; i < R; i += 2) {
        cout << "D";
        for (int j = 0; j < C - 1; j++) cout << 'L';
        cout << "D";
        for (int j = 0; j < C - 1; j++) cout << 'R';
    }
}

void minValue(int r, int c) {   // 최솟값 찾기
    int tmp = 1e9;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((i + j) % 2 != 0) {
                if (arr[i][j] < tmp) {
                    tmp = arr[i][j];
                    x = i;  // 행
                    y = j;  // 열
                }
            }
        }    
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    if (R % 2 != 0) {
        for (int i = 0; i < R / 2; i++) {
            for (int j = 0; j < C - 1; j++) cout << 'R';
            cout << "D";
            for (int j = 0; j < C - 1; j++) cout << 'L';
            cout << 'D';
        }
        for (int j = 0; j < C - 1; j++) cout << 'R';
    }
    else if (C % 2 != 0) {
        for (int j = 0; j < C / 2; j++) {
            for (int i = 0; i < R - 1; i++) cout << 'D';
            cout << 'R';
            for (int i = 0; i < R - 1; i++) cout << 'U';
            cout << 'R';
        }
        for (int i = 0; i < R - 1; i++) cout << 'D';
    }
    else {  // R, C 둘다 짝수
        minValue(R, C);
        f(x, y);
    }
}