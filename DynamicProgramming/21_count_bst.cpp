//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int countBST( int n)
{
  	ll dp[n+1];
	memset(dp,0,sizeof(dp));
    
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        dp[i]=0;
    	for(int j=0;j<i;j++){
            dp[i]=(dp[i]+((dp[j]*dp[i-j-1])%mod))%mod;
        }
    }
    return dp[n]%mod;
}

int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
