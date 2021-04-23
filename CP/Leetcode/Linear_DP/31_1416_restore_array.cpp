class Solution {
public:
    
    long long dp[100001];
    int mod = 1000000007;
    
    long long helper(string &s, int k, int ind) {
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        if(ind>=s.size()){
            return 1;
        }
        
        if(s[ind]=='0'){
            return 0;
        }
        
        int ans = 0;
        long long num = 0;
        // int i = ind;
        for(int i=ind;i<s.size();i++){
            //int n = s[i]-'0';
            num=num*10+s[i]-'0';
            
            if(num>k)
                break;
            
            ans=(ans + helper(s, k, i+1))%mod;
            // i++;
        }
        
        return dp[ind] = ans;
    }
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(s, k, 0);
    }
};