class Solution {
public:
    
    int dp[601][101][101];
    
    int ones(string s){
        int count = 0;
        for(auto i:s){
            if(i=='1'){
                count++;
            }
        }
        return count;
    }
    
    int zeroes(string s){
        int count = 0;
        for(auto i:s){
            if(i=='0'){
                count++;
            }
        }
        return count;
    }
    
    int helper(vector<string>&str, int len, int m, int n){
        if(len<0){
            return 0;
        }
        
        if(m<0 || n<0){
            return 0;
        }
        
        if(dp[len][m][n]!=-1){
            return dp[len][m][n];
        }
        
        int z = zeroes(str[len]);
        int o = ones(str[len]);
        
        if(z<=m && o<=n){
            int ans1 = 1 + helper(str, len-1, m-z, n-o);
            int ans2 = helper(str, len-1, m, n);
            return dp[len][m][n] = max(ans1, ans2);
        }
        
        return dp[len][m][n] = helper(str, len-1, m, n);
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(strs, strs.size()-1, m, n);
    }
};