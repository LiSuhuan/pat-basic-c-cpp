//
// Created by lenovo on 2023/6/11.
//
#include<iostream>
using namespace std;
int a[1000];
int main()
{
    int n,k,grad,num=0;
    cin>>n>>k>>grad;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        if(x>=175)
        {
            if(y>=grad) num++;        //特殊的不受批次影响
            else if(a[x]<k)
            {
                a[x]++;
                num++;                //普通的受批次影响的
            }
        }
    }
    cout<<num;
    return 0;
}