#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Bag{
    public:
    ll profit;
    ll weight;
};

Bag a[2001];
ll dp[2][2001][2001];
ll primes[11]={1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

bool cmp(Bag &b1, Bag&b2)
{
    if(b1.profit==b2.profit)
    {
        return b1.weight<b2.weight;
    }
    return b1.profit<b2.profit;
}

ll maxProfit(ll n, ll w)
{
 	for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=w;j++)
        {
            dp[0][i][j]=dp[0][i-1][j];
            if(j>=a[i-1].weight)
            {
                dp[0][i][j]=max(dp[0][i][j], dp[0][i-1][j-a[i-1].weight]+a[i-1].profit);
            }
        }
    }
    
    for(int p=1; p<=10; p++)
    {
        int index = p%2;
        
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=w; j++)
            {
             	dp[index][i][j] = dp[index][i-1][j]; // Exclude current element
                if(j>=a[i-1].weight)
                {
            		ll ans1 = dp[index][i-1][j-a[i-1].weight]+a[i-1].profit;  // Include but not mult.
                    ll ans2 = dp[index^1][i-1][j-a[i-1].weight]+a[i-1].profit*primes[p]; // Include and mult, if including 
                	// Particular prime no, we have to consider ans for previous prime no.
                    dp[index][i][j] = max(dp[index][i][j], max(ans1,ans2));
                }
            }
        }
    }
    return dp[0][n][w];
}

int main()
{
    ll n, w;
    cin>>n>>w;
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i].profit;
        cin>>a[i].weight;
    }
    
    memset(dp, 0, sizeof(dp));
    sort(a,a+n, cmp);
    
    cout<<maxProfit(n, w);
    
    return 0;
}
