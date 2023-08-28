//
// Created by lenovo on 2023/6/12.
//
#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *P = new int[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }
    int max = P[1];
    int sum = 0;
    int k = 1;
    unordered_map<int, int> v;
    for (int i = 1; i <= n; i++) {
        if (i == (pow(2, k) - 1)) {
            sum += P[i];
            v[k++] = sum;
            if (max < sum) {
                max = sum;
            }
            sum = 0;
        } else {
            sum += P[i];
        }
    }

    if (sum > max) {
        max = sum;
    }
    v[k] = sum;
    cout << max << endl;
    int flag = 1;
    for (int i = 1; i <= k; i++) {
        if (v[i] == max) {
            if (flag) {
                cout << i;
                flag = 0;
            }
            else cout << " " << i;
        }
    }

    return 0;
}
