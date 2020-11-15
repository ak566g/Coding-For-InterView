#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[1<<21];

ll specialPerm(ll mask,ll n)
{
    ll ans=0;
    if(mask==(1<<(n+1))-2)
    {
        return 1;
    }
    
    if(dp[mask]!=-1)
    {
        return dp[mask];
    }
    
    for(ll i=1;i<=n;i++)
    {
        if((mask&(1<<i))==0)
        {
            bool flag=true;
            for(ll j=i+1; j<=n;j++)
            {
                if((mask&(1<<j))==0 && (i&j)==i)
                {
					flag=false;
                }
            }
            
            if(flag)
            {
                ans+=specialPerm((mask|(1<<i)), n);
            }
        }
    }
    
    dp[mask]=ans;
    
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    
    for(int i=0;i<(1<<21);i++)
    {
        dp[i]=-1;
    }
    
    cout<<specialPerm(0,n);
}

