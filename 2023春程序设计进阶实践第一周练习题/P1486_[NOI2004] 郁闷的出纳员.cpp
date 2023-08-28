//
// Created by lenovo on 2023/6/11.
//
#include<iostream>

//三向切分快速排序
void quickSort(int a[], int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) std::swap(a[i], a[j]);
    }
    quickSort(a, l, j), quickSort(a, j + 1, r);
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
}