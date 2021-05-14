class Solution {
public:
    int inf = pow(10,7);
    int dp[505][505];
    int helper(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i>=nums1.size() || j>=nums2.size()){
            return -inf;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans1 = max(nums1[i]*nums2[j], nums1[i]*nums2[j] + helper(nums1, nums2, i+1, j+1));
        int ans2 = helper(nums1, nums2, i, j+1);
        int ans3 = helper(nums1, nums2, i+1, j);
        
        return dp[i][j] = max(ans1, max(ans2, ans3));
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return helper(nums1, nums2, 0, 0);
    }
};