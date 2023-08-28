//
// Created by Imp on 2023/6/10.
//
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;
int dis[N], p[N];//dis数组记录每个结点距离根节点长度，p数组记录每个结点的父节点

int sum = 0;

//定义DFS函数，参数为当前结点编号
int dfs(int u) {
    if (p[u] == -1 || dis[u] > 0)
        return dis[u];
    sum++;
    dis[u] = dfs(p[u]) + 1;
    return dis[u];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    int maxm = 0, d;
    while (m--) {
        cin >> d;
        maxm = max(maxm, dfs(d));//记录走过点的最深层
        cout << sum * 2 - maxm << endl;//输出结果
    }
    return 0;
}