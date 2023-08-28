//
// Created by Imp on 2023/6/12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//用二分查找将第i个数插入到前i个数中

void insertSort(vector<int> &nums, int i) {
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



void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int i = left;
    int j = right;
    int temp = nums[left];
    while (i < j) {
        while (i < j && nums[j] >= temp) j--;
        while (i < j && nums[i] <= temp) i++;
        if (i < j) swap(nums[i], nums[j]);
    }
    nums[left] = nums[i];
    nums[i] = temp;
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}
//直接插入排序
void insertSort1(vector<int> &nums, int i) {
    int temp = nums[i];
    int j;
    for (j = i - 1; j >= 0 && nums[j] > temp; j--) {
        nums[j + 1] = nums[j];
    }
    nums[j + 1] = temp;
}


    int main() {
        int N;
        cin >> N;
        vector<int> nums(N);
        for (int i = 0; i < N; i++) cin >> nums[i];

        for (int i = 0; i < N; i++) {
            insertSort1(nums, i);
            if (i == 0)cout << nums[i];
            else if (i == 1)cout << " " << (nums[0] + nums[1]) / 2;
            else if (i % 2 == 0) {
                int max = nums[i];
                int min = nums[0];
                int mid = nums[i / 2];
                cout << " " << (max + min + mid) / 3;
            } else if (i % 2 != 0) {
                int max = nums[i];
                int min = nums[0];
                int mid1 = nums[i / 2];
                int mid2 = nums[i / 2 + 1];
                cout << " " << (max + min + mid1 + mid2) / 4;
            }
        }

        return 0;
    }
