//
// Created by Imp on 2023/6/6.
//
#include<iostream>

using namespace std;

//求和函数：将整数的各位数字分别相加
int sum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n; //游戏轮数
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; //两个玩家的数字
        cin >> a >> b;
        int sum_a = sum(a);
        int sum_b = sum(b);
        if (a % sum_b == 0 && b % sum_a != 0) {
            cout << "A" << endl;
        } else if (b % sum_a == 0 && a % sum_b != 0) {
            cout << "B" << endl;
        } else if (a > b) {
            cout << "A" << endl;
        } else {
            cout << "B" << endl;
        }

    }
    return 0;
}