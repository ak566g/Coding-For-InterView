class Solution {
public:
    
    int dp[5001];
    
    int helper(vector<int>& prices, int current, int end){
        if(current>=end){
            return 0;
        }
        
        if(dp[current]!=-1){
            return dp[current];
        }
        
        int maxProfit = 0;
        
        for(int i=current+1;i<=end;i++){
            if(prices[current]<=prices[i]){
                maxProfit = max(prices[i]-prices[current]+helper(prices, i+2, end), maxProfit);
            }
        }
        
        maxProfit = max(maxProfit, helper(prices, current+1, end));
        
        return dp[current] = maxProfit;
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(prices, 0, prices.size()-1);
    }
};