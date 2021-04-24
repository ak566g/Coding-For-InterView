class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int count[n];
        dp[0]=1;
        count[0]=1;
        int len = 1;
        
        for(int i=1;i<n;i++){
            dp[i]=1;
            count[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        count[i] = count[j];
                    }else if(dp[i]==dp[j]+1){
                        count[i]+=count[j];
                    }
                }
            }
             
            len = max(len, dp[i]);
            
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            // cout<<count[i]<<" ";
            if(dp[i]==len)
                ans += count[i];
        }
        return ans;
    }
};