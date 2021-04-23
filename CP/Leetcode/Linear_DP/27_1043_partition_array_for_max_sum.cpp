class Solution {
public:
    
    int dp[501];
    
    int helper(vector<int>& arr, int cur, int k){
        if(cur>=arr.size()){
            return 0;
        }
        
        if(dp[cur]!=-1){
            return dp[cur];
        }
        
        int curmax = 0;
        int ans = 0;
        for(int i=cur;i<cur+k&&i<arr.size();i++){
            curmax = max(curmax, arr[i]);
            ans = max(ans, (i-cur+1)*curmax+helper(arr, i+1, k));
        }
        
        return dp[cur] = ans;
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(arr, 0, k);
    }
};