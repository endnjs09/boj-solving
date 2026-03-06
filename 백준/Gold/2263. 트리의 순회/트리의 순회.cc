#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 100001;
int inorder[SIZE], postorder[SIZE], idx[SIZE];    // 인덱스 저장

void f(int x, int y, int x_, int y_) {  // in_start, in_end, post_start, post_end
    if (x > y || x_ > y_) return;

    int p = postorder[y_];   // root(부모) = 1
    int p_index = idx[p];  // p_index = 3 

    cout << p << ' ';

    // [4 2 5] [1] [6 3]    
    // [4 5 2] [6 3] [1]
    int L = p_index - x;    // 왼쪽 길이 (3)
    f(x, p_index - 1, x_, x_ + L - 1);  // 왼쪽 [4 2 5] f(0, 2, 0, 2)
    f(p_index + 1, y, x_ + L, y_ - 1);  // 오른쪽 [6 3] f(4, 5, 3, 4)
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {   
        int num;
        cin >> num;
        inorder[i] = num;
        idx[num] = i;     
    }
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }

    f(0, N - 1, 0, N - 1);
}