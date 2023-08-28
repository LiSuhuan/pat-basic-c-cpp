//
// Created by lenovo on 2023/6/20.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//深度优先搜索，如果同时出现多个待访问的顶点，则优先选择编号最小的一个进行访问，
void dfs(vector<vector<int>>&edge,vector<bool>&visited,int s){
    visited[s]=true;
    cout<<s<<" ";
    for(int i=0;i<edge[s].size();i++){
        if(!visited[edge[s][i]]){
            dfs(edge,visited,edge[s][i]);
        }
    }
}
int main(){
    int n,m,s;
    cin>>n>>m>>s;
    vector<vector<int>>edge(n+5);
    //数组记录是否访问过
    vector<bool>visited(n+5,false);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        sort(edge[i].begin(),edge[i].end());
    }
    dfs(edge,visited,s);
    bool connected = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }
    if (!connected) {
        cout<<endl << "Non-connected";
    }
    return 0;
}