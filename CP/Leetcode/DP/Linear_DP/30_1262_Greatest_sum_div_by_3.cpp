class Solution {
public:
    
    int helper(vector<int>& nums){
        int n = nums.size();
        int dp[n][3];
        memset(dp, 0, sizeof(dp));
        
        dp[0][nums[0]%3] = nums[0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                int temp = nums[i]+dp[i-1][j];
                int rem = temp%3;
                dp[i][rem] = max(dp[i][rem], max(dp[i-1][rem], temp));
            }
            
            for(int j=0;j<3;j++){
                dp[i][j]=max(dp[i][j], dp[i-1][j]);
            }
        }
        
        return dp[n-1][0];
    }
    
    int maxSumDivThree(vector<int>& nums) {
        return helper(nums);
    }
};