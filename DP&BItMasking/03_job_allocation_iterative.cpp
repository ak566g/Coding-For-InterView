//by Ankita Gupta
#include<bits/stdc++.h>
using namespace std;
int n;
int jobCost[15][15];
int dp[1<<15];

int countSetBit(int n)
{
    int count =0;
    while(n>0)
    {
        if(n%2==1)
            count++;
        n=n/2;
    }
    return count;
}

int minAllocation()
{
    for(int i=0;i<(1<<n);i++)
    {
        dp[i]=INT_MAX;
    }
    dp[0]=0;

    for(int mask=0; mask<((1<<n)-1);  mask++)
    {
        int setbits = countSetBit(mask);
        for(int j=0; j<n; j++)
        {
            if((mask&(1<<j))==0)
            {
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask]+jobCost[setbits][j]);
            }
        }
    }

    return dp[(1<<n)-1];
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>jobCost[i][j];
        }
    }

    cout<<minAllocation();
}