class Solution {
public:
    
    int dp[101][101];
    
    int helper(vector<vector<int>>& grid, int m, int n){
        if(m<0 || n<0 || grid[m][n]==1){
            return 0;
        }
        
        if(m==0 && n==0){
            return 1;
        }
        
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        int ans1 = helper(grid, m-1, n);
        int ans2 = helper(grid, m, n-1);
        
        return dp[m][n] = ans1+ans2;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        return helper(obstacleGrid, m-1, n-1);
    }
};