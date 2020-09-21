#include <bits/stdc++.h>
using namespace std;
int dp[35][15][2];

int tradersProfit(int a[], int n, int k, bool ongoing)
{
    if(n==0)
        return 0;
    
    if(k==0)
        return 0;
    
    if(dp[n][k][ongoing]!=-1)
        return dp[n][k][ongoing];
    
    int option1;
    int option2;
    
    option1=tradersProfit(a+1,n-1,k,ongoing);
    
    if(ongoing==true)
    {
        option2=tradersProfit(a+1,n-1,k-1,0)+a[0];
    }
    else
    {
        if(k>0)
        option2=tradersProfit(a+1,n-1,k,1)-a[0];
    }
    
    dp[n][k][ongoing]= max(option1,option2);
    return dp[n][k][ongoing];
}

int main()
{
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int k;
        cin>>k;
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout<<tradersProfit(a,n,k,0)<<"\n";
    }
    
    return 0;
}
