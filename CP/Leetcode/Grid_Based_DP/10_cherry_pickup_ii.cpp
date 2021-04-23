class Solution {
public:
    
    int row , col;
    int dp[71][71][71];
    
    bool isValid(int i, int j){
        return i>= 0 && j>=0 && i<=row && j<=col;
    }
    
    int helper(int pr1, int pc1, int pr2, int pc2, vector<vector<int>>&grid){        
        
        if(!isValid(pr1, pc1) || !isValid(pr2, pc2)){
            return 0;
        }
        
        int temp[9];
        
        if(dp[pr1][pc1][pc2]!=-1){
            return dp[pr1][pc1][pc2];
        }
        
        temp[0] = helper(pr1+1, pc1-1, pr2+1, pc2-1, grid);
        temp[1] = helper(pr1+1, pc1-1, pr2+1, pc2, grid);
        temp[2] = helper(pr1+1, pc1-1, pr2+1, pc2+1, grid);
        
        temp[3] = helper(pr1+1, pc1, pr2+1, pc2-1, grid);
        temp[4] = helper(pr1+1, pc1, pr2+1, pc2, grid);
        temp[5] = helper(pr1+1, pc1, pr2+1, pc2+1, grid);
            
        temp[6] = helper(pr1+1, pc1+1, pr2+1, pc2-1, grid);
        temp[7] = helper(pr1+1, pc1+1, pr2+1, pc2, grid);
        temp[8] = helper(pr1+1, pc1+1, pr2+1, pc2+1, grid);
        
        int mm = 0;
        
        for(int i=0;i<9;i++){
            mm = max(mm, temp[i]);
        }
        
        if(pr1==pr2 && pc1==pc2){
            mm += grid[pr1][pc1];
        }
        else{
            mm += (grid[pr1][pc1]+ grid[pr2][pc2]);
        }
        return dp[pr1][pc1][pc2] = mm;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        row = grid.size()-1;
        col = grid[0].size()-1;
        
        memset(dp, -1, sizeof(dp));
        
        return helper(0,0,0, col, grid);
    }
};