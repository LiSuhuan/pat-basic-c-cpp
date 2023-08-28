//
// Created by Imp on 2023/6/7.
//
#include<iostream>
#include<stack>

using namespace std;

int main() {
    int n;//彩虹圈的个数
    cin >> n;
    int *arry = new int[n];//彩虹圈的直径
    for (int i = 0; i < n; i++) {
        cin >> arry[i]; //输入彩虹圈的直径
    }
    int m = 0;//宝塔的个数
    stack<int> S1;//A柱的彩虹圈
    stack<int> S2;//B柱的彩虹圈
    int max = 0;//最大的宝塔高度
    for (int i = 0; i < n; i++) {
        if (S1.empty() || S1.top() > arry[i]) {
            S1.push(arry[i]);
        } else if (!S1.empty() && S1.top() <= arry[i]) {
            if (S2.empty() || S2.top() < arry[i]) {
                S2.push(arry[i]);
            } else if (!S1.empty()) {
                int tempCount = 0;
                while (!S1.empty()) {
                    S1.pop();
                    tempCount++;
                }
                m++;
                if (tempCount > max) {
                    max = tempCount;
                }
                while (!S2.empty() && S2.top() > arry[i]) {
                    int temp = S2.top();
                    S2.pop();
                    S1.push(temp);
                }
                S1.push(arry[i]);
            }
        }
    }
    if (!S1.empty()) {
        int temp = 0;
        while (!S1.empty()) {
            S1.pop();
            temp++;
        }
        if (temp > max) {
            max = temp;
        }
        m++;
    }
    if (!S2.empty()) {
        int temp = 0;
        while (!S2.empty()) {
            S2.pop();
            temp++;
        }
        if (temp > max) {
            max = temp;
        }
        m++;
    }
    delete[] arry;
    cout << m << " " << max << endl;
    return 0;
}

