//by Ankita Gupta

// 4
// 10 2 6 5
// 1 15 12 8
// 7 8 9 3
// 15 13 4 10

#include<bits/stdc++.h>
using namespace std;
int n;
int jobCost[15][15];
int dp[1<<15];
int minAllocation(int p, int mask)
{
    int start =0;
    if(p>=n)
    {
        return 0;
    }
    if(dp[mask]!=-1)
    {
        return dp[mask];
    }

    int minimum =INT_MAX;
    for(int j=0;j<n;j++)
    {
        if((mask & (1<<j))==0)
        {
            int ans = minAllocation(p+1, mask|(1<<j)) + jobCost[p][j];
            minimum = min(ans, minimum);
        }
    }
    dp[mask] = minimum;
    return dp[mask];
}

int main(){
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>jobCost[i][j];
        }
    }

    cout<<minAllocation(0, 0);
}