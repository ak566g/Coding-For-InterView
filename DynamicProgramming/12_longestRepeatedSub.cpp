//by Ankita Gupta

using namespace std;

int countSubsequence(string s, int n){
    
    int dp[n+1][n+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
        dp[0][i]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=0;
            
            if(s[i-1]==s[j-1]&&i!=j){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    return dp[n][n];
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    
	    cout<<countSubsequence(s,n)<<"\n";
	}
	
	return 0;
}