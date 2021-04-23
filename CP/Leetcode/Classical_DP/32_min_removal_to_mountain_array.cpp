class Solution {
public:
    
    vector<int>lis(vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n, 1);
        
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
        }
        return dp;
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1 = lis(nums);
        reverse(nums.begin(), nums.end());
        vector<int>dp2 = lis(nums);
        reverse(dp2.begin(), dp2.end());
        int ans = n;
        
        for(int i=1;i<n-1;i++){
            // an index is mountain if it has atleast one element in left and one in right.
            if(dp1[i]>1 && dp2[i]>1){
                ans = min(ans, n-(dp1[i]+dp2[i]-1));
            }
        }
        
        return ans;
    }
};