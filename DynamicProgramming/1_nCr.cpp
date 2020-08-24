//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int mod= 1000000007;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,r;
	    cin>>n>>r;
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<=n;i++){
	        dp[i][i]=1;
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=i;j++){
	            if(j==1){
	                dp[i][j]=i%mod;
	            }
	            else{
	                dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
	            }
	        }
	    }
	   
	   cout<<dp[n][r]<<"\n"; 
	}
	
	return 0;
}