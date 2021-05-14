class Solution {
public:
    
    int dp[51][51][51];
    
    pair<int, int> helper(vector<vector<int>>& grid, int fi, int fj, int si, int sj, int m, int n){
        
        if(fi>m || fj>n || si>m || sj>n){
            return INT_MIN;
        }
        
        if(grid[fi][fj]==-1 || grid[si][sj]==-1){
            return INT_MIN;
        }
        
        if(fi==m && fj==n){
            return grid[m][n];
        }
        
        if(dp[fi][fj][sj]!=-1){
            return dp[fi][fj][sj];
        }
        
        int ans = grid[fi][fj];
        
        if(fj!=sj){
            ans += grid[si][sj];
        }
        
        int ans1 = helper(grid, fi+1, fj, si+1, sj, m, n);
        int ans2 = helper(grid, fi+1, fj, si, sj+1, m, n);
        int ans3 = helper(grid, fi, fj+1, si+1, sj, m, n);
        int ans4 = helper(grid, fi, fj+1, si, sj+1, m, n);
        
        
        ans += max(ans1, max(ans2, max(ans3, ans4)));
        
        return dp[fi][fj][sj] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans =  helper(grid, 0, 0, 0, 0, grid.size()-1, grid[0].size()-1);
        
        return ans>0?ans:0;
    }
};