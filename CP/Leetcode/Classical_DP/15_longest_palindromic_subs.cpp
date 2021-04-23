class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        string t = s;
        reverse(s.begin(), s.end());
        
        int dp[m+1][m+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][m];
    }
};