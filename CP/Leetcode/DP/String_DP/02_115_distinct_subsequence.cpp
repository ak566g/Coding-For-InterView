class Solution {
public:
    
    int dp[1001][1001];
    
    int helper(string s, string t, int sl, int i, int j){
        if(sl==t.size()){
            return 1;
        }
        
        
        if(i>=s.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans = 0;
        if(s[i]==t[j]){
            ans += helper(s, t, sl+1, i+1, j+1);
            ans += helper(s, t, sl, i+1, j);
        }else{
            ans += helper(s, t, sl, i+1, j);
        }
        return dp[i][j] = ans;
    }
    
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return helper(s, t, 0, 0, 0);
    }
};