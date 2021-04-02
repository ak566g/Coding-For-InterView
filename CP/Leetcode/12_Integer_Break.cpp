class Solution {
public:
    
    int dp[100];
    int helper(int n, int original){
        if(n==0||n==1){
            return 1;
        }
        
        if(n<0){
            return 0;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int ans = 0;
        
        for(int i=1;i<n; i++){
            ans = max(ans, helper(n-i, original)*i);
        }
        
        if(n!=original){
            return dp[n] = max(ans, n);
        }
        
        return dp[n] = ans;
    }
    
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n , n);
    }
};