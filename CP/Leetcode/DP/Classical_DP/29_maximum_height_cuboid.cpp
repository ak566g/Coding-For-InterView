class Solution {
public:
    
    static bool cmp(vector<int>&v1, vector<int>&v2){
        return v1[0] + v1[1] + v1[2] < v2[0] + v2[1] + v2[2];
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        
        
        for(int i=0;i<n;i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end(), cmp);
        
        int dp[n];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        
        for(int i=0;i<n;i++){
            dp[i] = cuboids[i][2];
            for(int j=i-1;j>=0;j--){
                if(cuboids[i][0]>=cuboids[j][0] && cuboids[i][1]>=cuboids[j][1] && cuboids[i][2]>=cuboids[j][2]){
                    dp[i] = max(dp[i], dp[j]+cuboids[i][2]);
                }
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};