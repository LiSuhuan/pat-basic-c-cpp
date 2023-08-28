//
// Created by lenovo on 2023/6/14.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
bool check(int k, int R, int C, vector<string>& cols) {
    unordered_set<string> s;
    for (int i = 0; i < C; i++) {
        if (s.count(cols[i].substr(k, R))) {
            return false;
        }
        s.insert(cols[i].substr(k,R));
    }
    return true;
}

int main() {
    // 读入矩阵大小和矩阵内容
    int R, C;
    cin >> R >> C;
    vector<string> matrix(R);
    for (int i = 0; i < R; ++i) {
        cin >> matrix[i];
    }
    vector<string> cols(C);
    for (int j = 0; j < C; ++j) {
        for (int i = 0; i < R; ++i) {
            cols[j] += matrix[i][j];
        }
    }
    // 二分搜索
    int l = 0, r = R-1;
    while (l < r) {
        int mid = (l+r+1) / 2;
        if (check(mid, R, C, cols)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    // 输出结果
    cout << l << endl;
    return 0;

}
