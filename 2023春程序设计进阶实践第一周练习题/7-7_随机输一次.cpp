//
// Created by Imp on 2023/6/9.
//
#include<iostream>

using namespace std;

int main() {
    int n;
    int *p = new int[n];
    cin>>n;
    int count[11] = {0};
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        count[i] += p[i];
    }
    string A = "ChuiZi";
    string B = "JianDao";
    string C = "Bu";
    string str = "K";
    int sum = 1;
    int cn = 0;
    for (int i = 0; i < n; i++) {
        cn += (count[i]+1);
    }
    while (str != "End") {
        cin >> str;
        if (str == "End") {
            break;
        }
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (sum == count[i]) {
                flag = 1;
                if (str == A) {
                    cout << B << endl;
                } else if (str == B) {
                    cout << C << endl;
                } else {
                    cout << A << endl;
                }
            }
            break;
        }
        sum%=cn;
        sum++;
        if (flag) {
            continue;
        } else {

            if (str == A) {
                cout << C << endl;

            } else if (str == B) {
                cout << A << endl;
            } else {
                cout << B << endl;
            }
        }


    }
    return 0;

}