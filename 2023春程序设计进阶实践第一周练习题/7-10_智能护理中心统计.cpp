//
// Created by Imp on 2023/6/11.
//
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int n , m , k , T , ans;
unordered_map<int,int>centre_ct;//护理中心对应的护理中心
unordered_map<int,int>older_ct;//老人对应的护理中心
unordered_map<string,int>encode;//转码,每个老人或者护理中心都转换为一个数字
int num[100005];
void add(int x){
    if(x == 0)return;
    num[x] ++;
    add(centre_ct[x]);
}
void sub(int x){
    if(x == 0)return;
    num[x] --;
    sub(centre_ct[x]);
}
void update(int x, int nu){
    if(x == 0)return ;
    num[x] += nu;
    update(centre_ct[x], nu);
}
int main(){
    cin >> n >> m;
    int idx = 0;
    while(m --){
        string a , b;
        cin >> a >> b;
        if(!encode[b])encode[b] = ++idx;
        if(a.back() >= '0' && a.back() <= '9'){
            older_ct[stoi(a)] = encode[b];
            add(encode[b]);
        }else{
            if(!encode[a])encode[a] = ++idx;
            centre_ct[encode[a]] = encode[b];
            update(encode[b], num[encode[a]]);
        }
    }
    char ch;
    while(cin >> ch){
        if(ch == 'E')break;
        if(ch == 'T'){
            int a ;string b;
            cin >> a >> b;
            if(older_ct[a] != 0)sub(older_ct[a]);
            older_ct[a] = encode[b];
            add(encode[b]);
        }else{
            string b;
            cin >> b;
            cout << num[encode[b]] << endl;
        }
    }
} 