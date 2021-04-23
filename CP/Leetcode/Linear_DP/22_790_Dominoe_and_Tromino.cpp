class Solution {
public:
    
    
    int mod = 1000000007;
    
    int dp[1005][4];
    
    int state(int n1, int n2){
        return n1*2+n2;
    }
    
    int helper(int n, int i, int t1, int t2){
        if(i==n){
            return 1;
        }
        
        int s = state(t1, t2);
        
        if(dp[i][s]!=-1){
            return dp[i][s];
        }
        
        int t3 = (i+1<n);
        int t4 = (i+1<n);
        
        int count = 0;
        
        // placing trominoes
        if(t1&&t2&&t3){
            count = (count + helper(n, i+1, false, true))%mod;
        }
        
        if(t1&&t2&&t4){
            count = (count + helper(n, i+1, true, false))%mod;
        }
        
        if(t1 && !t2 && t3 && t4 ){
            count = (count + helper(n, i+1, false, false))%mod;
        }
        
        if(!t1 && t2 && t3 && t4 ){
            count = (count + helper(n, i+1, false, false))%mod;
        }
        
        // placing dominoes
        if(t1 && t2){
            count = (count + helper(n, i+1, true, true))%mod;
        }
        
        if(t1 && t2 && t3 && t4){
            count = (count + helper(n, i+1, false, false))%mod;
        }
        
        if(t1 && !t2 && t3){
            count = (count + helper(n, i+1, false, true))%mod;
        }
        
        if(!t1 && t2 && t4){
            count = (count + helper(n, i+1, true, false))%mod;
        }
        
        if(!t1 && !t2){
            count = (count + helper(n, i+1, true, true))%mod;
        }
        
        return dp[i][s] = count;
    }
    int numTilings(int N) {
        memset(dp, -1, sizeof(dp));
        return helper(N,0, true, true);
    }
};