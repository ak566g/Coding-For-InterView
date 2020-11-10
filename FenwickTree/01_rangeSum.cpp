//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int bit[10000];
int a[10000];

void updateBIT(int val, int index, int n)
{
    for(;index<=n; index+= index&(-index))
    {
        bit[index]+=val;
    }
}

int queryBIT(int index)
{
    int sum=0;
    for(;index>0;index-=(index&(-index)))
    {
        sum+=bit[index];
    }
    return sum;
}

int main(){
    for(int i=0;i<10000;i++)
    {
        bit[i]=0;
        a[i]=0;
    }

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        updateBIT(a[i], i, n);
    }

    int q;
    cin>>q;
    while(q--)
    {
        int start, end;
        cin>>start>>end;
        cout<<queryBIT(end)-queryBIT(start-1)<<"\n";
    }

}