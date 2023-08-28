#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 20;
const int N = (1 << 19);
int k;
int a[M][N];
int ans[N], id[M][N];

int main() {
    cin >> k;

    int flag = 1, max1;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= (1 << (k - i)); j++) {
            cin >> a[i][j];

            if (i == 1) {
                ans[j * 2 - 1] = a[i][j];
                id[i][j] = j * 2;
            } else {
                max1 = max(a[i][j], max(a[i - 1][j * 2], a[i - 1][j * 2 - 1]));

                if (a[i][j] < a[i - 1][j * 2] && a[i][j] < a[i - 1][j * 2 - 1]) {
                    flag = 0;
                    break;
                } else if (a[i][j] >= a[i - 1][j * 2]) {
                    ans[id[i - 1][j * 2]] = a[i][j];
                    id[i][j] = id[i - 1][j * 2 - 1];
                } else {
                    ans[id[i - 1][j * 2 - 1]] = a[i][j];
                    id[i][j] = id[i - 1][j * 2];
                }
                a[i][j] = max1;
            }
        }
    }

    cin >> max1;

    if (a[k][1] <= max1)
        ans[id[k][1]] = max1;
    else
        flag = 0;

    if (flag == 0)
        cout << "No Solution"<<endl;
    else {
        for (int i = 1; i <= (1 << k); i++)
            cout << ans[i] << " \n"[i == (1 << k)];
    }

    return 0;
}