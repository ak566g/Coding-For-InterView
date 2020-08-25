//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int maxCuts(int x, int y, int z, int n){
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    dp[0]=0;
    for(int i=0;i<=n;i++){
        
        if(dp[i]==-1)
        continue;
        
        if(i+x<=n)
        {
            dp[i+x]=max(dp[i+x],1+dp[i]);
        }
        
        if(i+y<=n)
        {
            dp[i+y]=max(dp[i+y],1+dp[i]);
        }
        
        if(i+z<=n)
        {
            dp[i+z]=max(dp[i+z],1+dp[i]);
        }
    }
    return dp[n];
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    int x,y,z;
	    cin>>n;
	    cin>>x>>y>>z;
	    
	    cout<<maxCuts(x,y,z,n)<<"\n";
	}
	
	return 0;
}