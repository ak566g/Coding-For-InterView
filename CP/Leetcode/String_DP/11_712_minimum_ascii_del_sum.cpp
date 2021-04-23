class Solution {
public:
    
    // calculate longest common subsequence with highest ascii sum.
    // then subtract it from non common part.
    // ans will be sum_s1 + sum_s2 - 2*lcs_ascii.
    
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        int dp[m+1][n+1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]= s1[i-1]+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int s1_sum = 0, s2_sum = 0;
        
        for(int i=0;i<s1.size();i++){
            s1_sum += s1[i];
        }
        
        for(int i=0;i<s2.size();i++){
            s2_sum += s2[i];
        }
        
        return s1_sum + s2_sum - 2 * dp[m][n];
    }
};