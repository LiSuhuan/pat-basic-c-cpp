//
// Created by lenovo on 2023/6/10.
//
#include<iostream>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    int **a = new int *[n + 1];
    for (int i = 1; i <= n; i++) {
        a[i] = new int[n + 1];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    //对矩阵进偶数列行列平移，并用x填充平移后的位置
    int k1=1;
    for (int j = 2; j <= n; j += 2) {
        int temp = n;
        for (int i = n-k1; i >= 1; i--) {
            a[temp--][j]=a[i][j];
        }
        for(int i=1;i<=k1;i++){
            a[i][j]=x;
        }
        if(k1==k)
            k1=1;
        else
            k1++;
    }

    //在一行中输出平移后第 1 到 n 行元素的和。数字间以 1 个空格分隔，行首尾不得有多余空格。
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += a[i][j];
        }
        if(i==1)cout<<sum;
        else
        cout<<" "<< sum;
    }

delete[] a;
    return 0;
}