class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minP = nums[0];
        int maxP = nums[0];
        int ans = nums[0];
        
        for(int i=1;i<nums.size();i++){
            int temp1 = minP*nums[i];
            int temp2 = maxP*nums[i];
            
            maxP = max(nums[i], max(temp1, temp2));
            minP = min(nums[i], min(temp1, temp2));
            
            ans = max(ans, maxP);
        }
        
        return ans;
    }
};