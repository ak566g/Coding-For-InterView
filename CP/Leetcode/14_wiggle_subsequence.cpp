class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int s=nums.size();
        if(s<=1){
            return s;
        }
        
        
        int p=1;
        int n=1;
        
        for(int i=1;i<s;i++){
            if(nums[i]>nums[i-1]){
                p=n+1;
            }else if(nums[i]<nums[i-1]){
                n=p+1;
            }
        }
        
        return max(p,n);
    }
};