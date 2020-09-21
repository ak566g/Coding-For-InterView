//by Ankita Gupta

// Question Link
// https://www.spoj.com/problems/SQRBR/

#include <bits/stdc++.h>
using namespace std;
bool b[40];
int dp[50][50];

int brackets(int size, int n, int o, int c, int index)
{
    
    if(o>n || c>n)
        return 0;
    
    if(o==n && c==n)
    {
        return 1;
    }
    
    if(dp[o][c]!=-1)
        return dp[o][c];
    
    if(b[index]==true || o==c)
    {
        dp[o][c]= brackets(size-1,n,o+1,c,index+1);
    }
    else if(o==n)
    {
        dp[o][c]= brackets(size-1,n,o,c+1,index+1);
    }
    else {
        dp[o][c]= brackets(size-1,n,o+1,c,index+1)+brackets(size-1,n,o,c+1,index+1);
    }
    
    return dp[o][c];
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n , k;
        cin>>n>>k;
        
        memset(b,false,sizeof(b));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<k;i++)
        {
            int x;
            cin>>x;
            b[x]=true;
        }
        b[1]=true;
        
        cout<<brackets(2*n,n,0,0,1)<<"\n";
    }
    return 0;
}
