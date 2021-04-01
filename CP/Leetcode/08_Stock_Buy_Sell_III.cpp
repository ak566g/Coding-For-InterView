class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int dp[n];
        dp[0]=0;
        int leftMin = prices[0];
        
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1], prices[i]-leftMin);
            leftMin = min(leftMin, prices[i]);
        }
        
        int rightMax = prices[n-1];
        
        for(int i=n-2;i>=0;i--){
            dp[i]=max(dp[i+1], dp[i]+rightMax-prices[i]);
            rightMax=max(rightMax, prices[i]);
        }
        return dp[0];
    }
};