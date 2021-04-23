// same as longest palindromic subsequence.
// find out the longest palindromic subsequence and ans will be s.size()-lis

class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        reverse(s.begin(), s.end());
        int n=s.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};