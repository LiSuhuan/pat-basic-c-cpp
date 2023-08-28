#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp(end - start + 1);
    long long inversions = 0;

    int i = start;  // 左半部分数组的起始位置
    int j = mid + 1;  // 右半部分数组的起始位置
    int k = 0;  // 合并后数组的起始位置

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // 当 arr[i] > arr[j] 时，arr[i] 及其后面的元素都与 arr[j] 构成逆序对
            inversions += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // 将排序后的结果复制回原数组 arr
    for (int p = 0; p < temp.size(); p++) {
        arr[start + p] = temp[p];
    }

    return inversions;
}

long long mergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        long long inversions = 0;

        // 分治递归
        inversions += mergeSort(arr, start, mid);
        inversions += mergeSort(arr, mid + 1, end);

        // 合并子数组并计算逆序对数量
        inversions += merge(arr, start, mid, end);

        return inversions;
    }

    return 0;
}

long long countPermutations(int n, int C) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    return mergeSort(arr, 0, n - 1) == C;
}

int main() {
    int n, C;
    cout << "Enter the length of the sequence (n): ";
    cin >> n;
    cout << "Enter the number of inversions (C): ";
    cin >> C;

    long long permutations = countPermutations(n, C);

    cout << "Total number of permutations with " << C << " inversions: " << permutations << endl;

    return 0;
}
