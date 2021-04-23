class Solution {
public:
    
    int dp[501][5001];
    
    int helper(int amount, vector<int>&coins, int cur) {
        if(amount==0){
            return 1;
        }
        
        if(amount<0 || cur>=coins.size()){
            return 0;
        }
        
        if(dp[cur][amount]!=-1){
            return dp[cur][amount];
        }
        
        int inc = helper(amount-coins[cur], coins, cur);
        int exc = helper(amount, coins, cur+1);
        
        return dp[cur][amount]=inc+exc;
        
    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return helper(amount, coins, 0);
    }
};