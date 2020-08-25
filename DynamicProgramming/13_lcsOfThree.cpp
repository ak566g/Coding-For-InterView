//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int LCSThree(string a, string b, string c,int m,int n,int o)
{
    int dp[m+1][n+1][o+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=o;k++){
                
                if(a[i-1]==b[j-1]&&a[i-1]==c[k-1]){
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                }else{
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    
    return dp[m][n][o];
}

int main()
 {
	//code
	
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n,o;
	    cin>>m>>n>>o;
	    
	    string a,b,c;
	    cin>>a>>b>>c;
	    
	    cout<<LCSThree(a,b,c,m,n,o)<<"\n";
	}
	
	return 0;
}