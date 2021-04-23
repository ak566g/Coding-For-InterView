class Solution {
public:
    
    int dp[201][201];
    
    int helper(vector<vector<int>>& grid, int m, int n){
        if(m<0 || n<0){
            return INT_MAX-200;
        }
        
        if(m==0 && n==0){
            return grid[m][n];
        }
        
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        int ans1 = grid[m][n] + helper(grid, m-1, n);
        int ans2 = grid[m][n] + helper(grid, m, n-1);
        
        return dp[m][n] = min(ans1, ans2);
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        // memset(dp, -1, sizeof(dp));
        // return helper(grid, m-1, n-1);
        
        for(int i=1;i<=n;i++){
            grid[0][i] += grid[0][i-1];
        }
        
        for(int j=1;j<=m;j++){
            grid[j][0] += grid[j-1][0];
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                grid[i][j]= grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m][n];
    }
};