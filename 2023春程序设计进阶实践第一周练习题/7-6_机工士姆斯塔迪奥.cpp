//
// Created by lenovo on 2023/6/9.
//
#include<iostream>

using namespace std;

int main() {
    int N;    //行大小
    int M;    //列大小
    int Q;    //行或列数量
    cin >> N >> M >> Q;
    int a[N + 1][M + 1] = {0};
    int sum = 0;
    for (int i = 0; i < Q; i++) {
        int T, C;
        cin >> T >> C;
        if (T == 0) {
            for (int m = C, j = 1; j <= M; j++) {
                if (a[C][j] == 0) {
                    a[C][j] = 1;
                    sum++;
                }
            }
        } else if (T == 1) {
            for (int n = C, j = 1; j <= N; j++) {
                if (a[j][C] == 0) {
                    a[j][C] = 1;
                    sum++;
                }
            }
        }
    }
    cout << N * M - sum;
}