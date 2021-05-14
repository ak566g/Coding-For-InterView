// can be solved as variation of lis

class Solution {
public:
    
    bool cmp(vector<string>& strs, int i, int cur){
        for(int k=0;k<strs.size();k++){
            if(strs[k][i]>strs[k][cur])
                return false;
        }
        return true;
    }
    
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        int dp[n];
        dp[0]=1;
        int ans = 1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(cmp(strs, j, i)){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return n-ans;
    }
};