class Solution {
public:
    
    int inf = 1000000;
    
    int dp[10005];
    
    int helper(vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }
        
        if(dp[amount]!=-1){
            return dp[amount];
        }
        
        int ans = inf;
        
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                int temp = helper(coins, amount-coins[i]);
                
                if(temp<ans){
                    ans = 1+temp;
                }
            }
        }
        return dp[amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans =  helper(coins, amount);
        return ans>=inf?-1:ans;
    }
};