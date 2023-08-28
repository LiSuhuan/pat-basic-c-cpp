//
// Created by lenovo on 2023/6/6.
//
#include<iostream>
#include<cmath>
#include<vector>
using namespace  std;
// 求一个数的因数并存储在数组中
vector<int> getFactor(int n){
    vector<int> factor;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            factor.push_back(i);
        }
    }
    return factor;
}
void bubbleSort(vector<int> &arr){
    int len=arr.size();
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main() {
//N0,N1,N分别对应女生人数、男生人数、寝室数。
    int N0;
    int N1;
    int N;
    cin >> N0 >> N1 >> N;
    vector<int> factor0 = getFactor(N0);  // N0的因数
    vector<int> factor1 = getFactor(N1);  // N1的因数
    bubbleSort(factor0);    // 对因数进行排序
    bubbleSort(factor1);    // 对因数进行排序
    int min =N1+N0;
    int ans1=0;
    int ans2=0;
    int j1 = factor0.size();
    int j2 = factor1.size();
    for (int i = 0; i < j1; i++) {
        for (int j = 0; j < j2; j++) {
            if (factor0[i] + factor1[j] == N && abs(N0/factor0[i] - N1/factor1[j]) <= min) {
                min = abs(N0/factor0[i] - N1/factor1[j]);
                ans1=factor0[i];
                ans2=factor1[j];
            }         // 两个因数相加等于N且小于min
        }
    }

    if (min == N+1) {
        cout << "No Solution";

    }
    else{
        cout<<ans1<<" "<<ans2;
    }
}