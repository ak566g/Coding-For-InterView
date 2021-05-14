class Solution {
public:
    
    int dp[501][501];
    int mod = 1000000007;
    
    long long helper(int n, int pic, int del){
        if(del == n){
            return 1;
        }
        
        if(dp[pic][del]!=-1){
            return dp[pic][del];
        }
        
        long long ans = 0;
        
        if(pic+del<n){
            ans = (ans + (n-pic-del) * helper(n, pic+1, del))%mod;
        }
        
        if(pic>0){
            ans = (ans + pic * helper(n, pic-1, del+1))%mod;
        }
        
        return dp[pic][del] = ans%mod;
        
    }
    
    int countOrders(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n, 0, 0)%mod;
    }
};