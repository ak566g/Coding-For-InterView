class Solution {
public:
    
    int dp[205][20001];
    
    bool subsetSum(vector<int>& nums, int curr, int sum, int val){
        if(val==sum){
            return true;
        }
        
        if(curr>=nums.size()){
            return false;
        }
        
        if(dp[curr][val]!=-1){
            return dp[curr][val];
        }
        
        return dp[curr][val] = subsetSum(nums, curr+1, sum, val+nums[curr])||subsetSum(nums, curr+1, sum, val);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2){
            return false;
        }
        
        memset(dp, -1, sizeof(dp));
        return subsetSum(nums, 0, sum/2, 0);
    }
};