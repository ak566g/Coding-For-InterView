class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int m = d.size()-1;
        int n = d[0].size()-1;
        
        
        int dp[m+1][n+1];
        
        dp[m][n] = d[m][n]>0?0:d[m][n];
        
        for(int i=m-1;i>=0;i--){
            int num = d[i][n] + dp[i+1][n];
            dp[i][n] = num<0?num:0;            
        }
        
        for(int j=n-1;j>=0;j--){
            int num = d[m][j] + dp[m][j+1];
            dp[m][j] = num<0?num:0;
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int num = d[i][j] + max(dp[i+1][j], dp[i][j+1]);
                
                dp[i][j] = num<0?num:0;
            }
        }
        
        return abs(dp[0][0])+1;
    }
};