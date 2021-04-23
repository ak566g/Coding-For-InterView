class Solution {
public:
    
    int mod = 1000000007;
    
    int x[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int y[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    
    int dp[5001][4][3];
    
    bool isValid(int i, int j){
        if(i>=0 && i<=3 && j>=0 && j<=2 && !(i==3 && j==0) && !(i==3 && j==2)){
            return true;
        }
        return false;
    }
    
    int helper(int n, int cur, int i, int j){
        if(cur==n){
            return 1;
        }
        
        if(dp[cur][i][j]!=-1){
            return dp[cur][i][j];
        }
        
        int count = 0;
        for(int k = 0; k < 8; k++){
            if(isValid(i+x[k], j+y[k])){
                count = (count + helper(n, cur+1, i+x[k], j+y[k]))%mod;
            }
        }
        
        return dp[cur][i][j] = count%mod;
    }
    
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                ans = (ans + helper(n-1, 0, i, j))%mod;
            }
        }
        ans = (ans + helper(n-1, 0, 3, 1))%mod;
        return ans;
    }
};