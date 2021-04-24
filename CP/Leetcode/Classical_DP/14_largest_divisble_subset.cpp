class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int dp[n];
        dp[0]=1;
        
        int ans = 1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        vector<int>res;
        // cout<<ans;
        int prev = 0;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==ans && prev%nums[i]==0){
                res.push_back(nums[i]);
                prev=nums[i];
                ans--;
            }
        }
        return res;
    }
};