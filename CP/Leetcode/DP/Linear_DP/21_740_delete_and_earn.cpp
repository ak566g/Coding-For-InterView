// similar to house robber problem

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int hash[10001];
        int dp[10001];
        memset(hash, 0, sizeof(hash));
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]+=nums[i];
        }
        
        dp[0]=0;
        dp[1]=hash[1];
        
        for(int i=2;i<=10000;i++){
            dp[i] = max(dp[i-1], hash[i]+dp[i-2]);
        }
        return dp[10000];
    }
};