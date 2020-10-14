//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int weightCapacity(vector<int>v, int maxWeight)
{
    int n=v.size();
    int dp[n+1][maxWeight+1];

    for(int i=0; i<=n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(v[i-1]<=j)
            {
                dp[i][j]=max(v[i-1]+dp[i-1][j-v[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
            
        }
    }

    return dp[n][maxWeight];
}


int main(){

    int n;
    cin>>n;

    vector<int>v;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        v.push_back(x);
    }

    int maxWeight;
    cin>>maxWeight;

    cout<<weightCapacity(v, maxWeight);

}