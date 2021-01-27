//by Ankita Gupta

// find highest i such that nums[i]<nums[i+1]
// if no such index exist then there is no next permutation.

// find the highest j > i such that s[j]>s[i]

// swap s[i] and s[j]

// reverse the elements after i.


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        
        while(i>=1 && nums[i-1]>=nums[i]){
            i--;
        }
        
        if(i<=0){
            sort(nums.begin(),nums.end());
            return;
        }
        else{
            int j = n-1;
            while(nums[j]<=nums[i-1])
            {
                j--;
            }
            swap(nums[i-1], nums[j]);
            j=n-1;
            while(i<j){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
    }
};