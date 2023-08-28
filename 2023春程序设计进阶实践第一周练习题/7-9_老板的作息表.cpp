//
// Created by Imp on 2023/6/10.
//
#include<iostream>
#include<string>
#include<vector>

using namespace std;
struct node{
    string begin,end;
}boss_time[10005];
bool compare(node &a,node &b){
    return a.begin>b.begin;
}
//sort函数
void sort(node *a,node *b,bool (*cmp)(node &a,node &b)){
    for(node *i=a;i<b;i++){
        for(node *j=i+1;j<b;j++){
            if(cmp(*i,*j)){
                node temp=*i;
                *i=*j;
                *j=temp;
            }
        }
    }
}

int main(){
    int N;
    char ch;
    string b="00:00:00";
    string e="23:59:59";
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>boss_time[i].begin>>ch>>boss_time[i].end;
    }
    sort(boss_time, boss_time + N, compare);
    for(int i=0;i<N;i++){
        if(b!=boss_time[i].begin)
            cout<<b<<" - "<<boss_time[i].begin<<endl;
        b=boss_time[i].end;
    }if(b!=e){
        cout<<b<<" - "<<e;
    }return 0;
}