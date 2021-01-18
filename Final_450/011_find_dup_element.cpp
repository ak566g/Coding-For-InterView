// This solution has intitution from Graph--> Floyyed warshal algo.
// Isme linked list bnaenge

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast=nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        fast = nums[0];
        
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return fast;
    }
};

// This is only applicable for mutable array. 
// Isme index wale element ko negative kr de rhe h, jisse ki agr us index pe phuche or wo negative h to
// Phle bhi mil chuka h.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i=0;i<nums.size();i++)
        {
            if(nums[(abs(nums[i])-1)]>=0)
            {
                nums[(abs(nums[i])-1)]*=-1;
            }
            else
            {
                return abs(nums[i]);
            }
        }
        return 0;
    }
};