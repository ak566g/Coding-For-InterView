class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0];
        }
        
        if(nums.size()==2){
            return max(nums[0], nums[1]);
        }
        
        int n = nums.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        
        dp[1] = nums[0];
        
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
        }
        
        int ans1 = dp[n-1];
        
        memset(dp, 0, sizeof(dp));
        
        dp[1] = nums[1];
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        int ans2 = dp[n-1];
        return max(ans1, ans2);
    }
};