class Solution {
public:
    int helper(vector<int>& nums, int start, int end, long long S){
        if(start>end){
            if(S==0)
                return 1;
            return 0;
        }
        int add = helper(nums, start+1, end, S+nums[start]);
        int sub = helper(nums, start+1, end, S-nums[start]);
        return add+sub;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        return helper(nums, 0, nums.size()-1, S);
    }
};