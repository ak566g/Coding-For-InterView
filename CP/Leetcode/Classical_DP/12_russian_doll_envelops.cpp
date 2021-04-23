class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end());
        
        int dp[e.size()];
        dp[0]=1;
        int ans=1;
        for(int i=1;i<e.size();i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(e[i][0]>e[j][0] && e[i][1]>e[j][1]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};