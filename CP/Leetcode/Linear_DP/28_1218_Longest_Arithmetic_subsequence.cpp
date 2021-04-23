class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 1;
        unordered_map<int, int>um;
        
        for(int i=0;i<arr.size();i++){
            um[arr[i]] = 1 + um[arr[i]-difference];
            ans = max(ans, um[arr[i]]);
        }
        
        return ans;
    }
};