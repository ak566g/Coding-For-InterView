class Solution {
public:
    
    int mod = pow(10, 9) + 7;
    
    int helper(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        pair<long long,long long>dp[m+1][n+1];
        
        // first for minimum,
        // second for maximum
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j].first = grid[i][j];
                    dp[i][j].second = grid[i][j];
                }
                else if(i==0){
                    dp[i][j].first = grid[i][j]*dp[i][j-1].first;
                    dp[i][j].second =grid[i][j]*dp[i][j-1].second;
                }else if(j==0){
                    dp[i][j].first = grid[i][j]*dp[i-1][j].first;
                    dp[i][j].second = grid[i][j]*dp[i-1][j].second;
                }
                else{
                    long long x1 = min(grid[i][j]*dp[i][j-1].first, grid[i][j]*dp[i][j-1].second); //minimum from left
                    long long y1 = min(grid[i][j]*dp[i-1][j].first, grid[i][j]*dp[i-1][j].second); //minimum from up
                    
                    long long x2 = max(grid[i][j]*dp[i][j-1].first, grid[i][j]*dp[i][j-1].second); //maximum from left
                    long long y2 = max(grid[i][j]*dp[i-1][j].first, grid[i][j]*dp[i-1][j].second); //maximum from up
                    
                    
                    
                    dp[i][j].first = min(x1, y1);
                    dp[i][j].second = max(x2, y2);
                }
            }
        }
        return dp[m-1][n-1].second< 0 ? -1: (dp[m-1][n-1].second%mod);
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        
        int ans =  helper(grid);
        return ans;
    }
};