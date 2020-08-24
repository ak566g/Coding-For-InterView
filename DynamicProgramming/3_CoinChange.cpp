//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int noOfWays(int *denominations, int n, int target)
{
    int dp[n+1][target+1];
    for(int i=0;i<=target;i++){
        dp[0][i]=0;
    }
    
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(j>=denominations[i-1]){
                int x=dp[i-1][j];
                int y=dp[i][j-denominations[i-1]];
                dp[i][j]=x+y;
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

int main()
 {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int *denominations= new int[n];
	    
	    for(int i=0;i<n;i++){
	        cin>>denominations[i];
	    }
	    
	    int target;
	    cin>>target;
	    
	    cout<<noOfWays(denominations,n,target)<<"\n";
	    
	}
	
	return 0;
}