//
// Created by lenovo on 2023/6/11.
//
#include<iostream>
#include<vector>

using namespace std;
const int N = 10000;
int GGGGG[N][N], Gender[N], d[N];

//归并排序
void mergeSort(int a[], int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    mergeSort(a, l, mid), mergeSort(a, mid + 1, r);
    int i = l, j = mid + 1, k = 0, tmp[r - l + 1];
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) GGGGG[i][j] = 0;
            else GGGGG[i][j] = 1e9;

    for (int i = 1; i <= n; i++) {
        char GOD;
        int wps;
        cin >> GOD >> wps;
        if (GOD == 'F') Gender[i] = 1;//女生
        else Gender[i] = 2;//男生
        for (int j = 1; j <= wps; j++) {
            int a, b;
            scanf("%d:%d", &a, &b);
            GGGGG[i][a] = b;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                GGGGG[i][j] = min(GGGGG[i][j], GGGGG[i][k] + GGGGG[k][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (Gender[i] != Gender[j])
                d[i] = max(d[i], GGGGG[j][i]);

    int dis1 = 1e9, dis2 = 1e9;
    for (int i = 1; i <= n; i++) {
        if (Gender[i] == 2) dis1 = min(dis1, d[i]);
        else dis2 = min(dis2, d[i]);
    }

    vector<int> a, b;
    for (int i = 1; i <= n; i++)//女性的"大众情人"
    {
        if (Gender[i] == 2) continue;
        if (d[i] == dis2) a.push_back(i);
    }

    for (int i = 1; i <= n; i++)//男性的"大众情人"
    {
        if (Gender[i] == 1) continue;
        if (d[i] == dis1) b.push_back(i);
    }


    cout << a[0];
    for (int i = 1; i < (int) a.size(); i++)

        cout << " " << a[i];

    puts("");


    cout << b[0];
    for (int i = 1; i < (int) b.size(); i++)

        cout << " " << b[i];

    return 0;
}
