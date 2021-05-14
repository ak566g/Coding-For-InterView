class Solution {
public:
    
    int dp[100001];
    
    bool helper(int n){
        
        if(n==0 || n==2){
            return false;   // in this case first player will lose game.
        }
        
        if(n==1){
            return true;    // in this case first player will win game.
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        for(int i=1;i*i<=n;i++){
            if(!helper(n-i*i)){     // checking returned answer is false, then first person will win the game.
                return dp[n] = true;    
            }
        }
        
        return dp[n] = false;
    }
    
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};