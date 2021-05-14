class Solution {
public:
    
    bool helper(string s, string p){
        int m = p.size();
        int n = s.size();
        bool dp[m+1][n+1];
        
        memset(dp, false, sizeof(dp));
        dp[0][0]=true;
        
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*'){
                    dp[i][0]=dp[i-2][0];
            }else{
                dp[i][0]=false;
            }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[i-1]=='*'){
                    if(p[i-2]==s[j-1] || p[i-2]=='.')
                        dp[i][j] = max(dp[i][j-1], dp[i-2][j]);
                    else
                        dp[i][j] = dp[i-2][j];
                }else{
                    dp[i][j]=false;
                }
            }
        }
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        
        return dp[m][n];
    }
    
    bool isMatch(string s, string p) {
        return helper(s, p);
    }
};