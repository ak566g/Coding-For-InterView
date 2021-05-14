class Solution {
public:
    
    int dp[50001][2];
    
    int helper(vector<int>& prices, int cur ,int state, int fee){
        if(cur>=prices.size()){
            return 0;
        }
        
        int profit = 0;
        
        if(dp[cur][state]!=-1){
            return dp[cur][state];
        }
        
        if(state==0){
            profit = max(profit, helper(prices, cur+1, 1, fee)-prices[cur]-fee);
            profit = max(profit, helper(prices, cur+1, 0, fee));
        }else{
            profit = max(profit, helper(prices, cur+1, 0, fee)+prices[cur]);
            profit = max(profit, helper(prices, cur+1, 1, fee));
        }
        return dp[cur][state] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return helper(prices, 0, 0, fee);
    }
};