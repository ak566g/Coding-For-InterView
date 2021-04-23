class Solution {
public:
    
    long long dp[100001][2][3];
    int mod = 1000000007;
    
    int helper(int n, int absent, int cons_abs){
        
        // order of base case is very important
        if(cons_abs>2||absent>1){
            return 0;
        }
        
        if(n==0){
            return 1;
        }
        
        if(dp[n][absent][cons_abs]!=-1){
            return dp[n][absent][cons_abs];
        }
        
        long long first = helper(n-1, absent, 0);             //present
        long long second = helper(n-1, absent+1, 0);          //absent
        long long third = helper(n-1, absent, cons_abs+1);    //late
        
        return dp[n][absent][cons_abs] = (first+second+third)%mod;
    }
    
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n, 0, 0)%mod;
    }
};
