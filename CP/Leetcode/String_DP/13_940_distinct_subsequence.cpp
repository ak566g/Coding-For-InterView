class Solution {
public:
    
    int mod = pow(10, 9) + 7;
    
    int distinctSubseqII(string s) {
        unordered_map<char, int>um;
        int n = s.size();
        long dp[n+1];
        dp[0]=1;
        
        for(int i=1;i<=n;i++){
            dp[i] = (dp[i-1]*2)%mod;
            
            if(um.count(s[i-1])>0){
                dp[i] = (dp[i] - dp[um[s[i-1]]-1] + mod)%mod;
            }
            
            um[s[i-1]]=i;
        }
        
        return dp[n]-1;
    }
};