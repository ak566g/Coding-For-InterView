#include <bits/stdc++.h>
using namespace std;
void solve(int x,int n,int& count,int sum,int num)
{
    if(sum==0)
    {
    ++count;
    return;
    }
    int p=pow(num,n);
    if(p>x)
    return;
    int op1 = sum;
    int op2 = sum;
    op1 = op1 - p;
    if(op1>=0)
    solve(x,n,count,op1,num+1);
    solve(x,n,count,op2,num+1);
    return;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int x,n;
cin>>x;
cin>>n;
int count=0;
solve(x,n,count,x,1);
cout<<count;
return 0;
}