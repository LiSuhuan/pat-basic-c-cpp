//
// Created by lenovo on 2023/6/15.
//
#include <iostream>
#include <vector>
#include <algorithm>

//将第i位数字插入到前面的有序数组中
void insertSort(std::vector<int> &nums, int i) {
    int left = 0;
    int right = i - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] > nums[i]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    int temp = nums[i];
    for (int j = i - 1; j >= left; j--) {
        nums[j + 1] = nums[j];
    }
    nums[left] = temp;
}


using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> maxSums;
    vector<int> aValues(N);
    vector<int> bValues(N);

    for (int i = 0; i < N; i++) {

        cin >> aValues[i] >> bValues[i];

    }

    for (int i = 0; i < N; i++) {
        insertSort(aValues, i);
        insertSort(bValues, i);

        int right=0,left=0;
        int maxSum = 0;
        //二分法最小化最大值
      while(left<=right) {
        int mid=(left+right)/2;
        if(aValues[mid]+bValues[i-mid]>=aValues[mid+1]+bValues[i-mid-1]&&mid+1<=i&&i-mid-1>=0) {
            maxSum=aValues[mid]+bValues[i-mid];
            right=mid-1;
        } else {
            if(mid+1<=i&&i-mid-1>=0)
            maxSum=aValues[mid+1]+bValues[i-mid-1];
            else maxSum=aValues[mid]+bValues[i-mid];
            left=mid+1;
        }
      }

        maxSums.push_back(maxSum);
    }

    for (int sum: maxSums) {
        cout << sum << endl;
    }

    return 0;
}
