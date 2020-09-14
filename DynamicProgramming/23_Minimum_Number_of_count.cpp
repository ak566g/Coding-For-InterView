//by Ankita Gupta

// Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
// Output will be 1, as 1 is the minimum count of numbers required.

#include<bits/stdc++.h>
using namespace std;

int minCount(int n)
{
	int dp[n+1];
    memset(dp,0,sizeof(dp));
    
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        if(sqrt(i)-floor(sqrt(i))==0)
            dp[i]=1;
        else{
            dp[i]=i;
            for(int j=1;j<=sqrt(i);j++)
            {
				dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
    }
    
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
