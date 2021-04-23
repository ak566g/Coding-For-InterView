class Solution {
public:
    
    int mod = 1000000007;
    
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        long long dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        // array for storing prev available current char.
        int prev[n];
        // array for storing next available current char
        int next[n];
        
        unordered_map<char , int>um;
        
        // storing prev
        for(int i=0;i<n;i++){
            if(um.count(s[i])>0){
                prev[i]=um[s[i]];
            }else{
                prev[i]=-1;
            }
            um[s[i]]=i;
        }
        
        um.clear();
        
        for(int i=n-1;i>=0;i--){
            if(um.count(s[i])>0){
                next[i]=um[s[i]];
            }else{
                next[i]=-1;
            }
            um[s[i]]=i;
        }
        
        for(int g=0; g<n; g++){
            for(int r=0, c=g; r<n && c<n ; r++, c++){
                if(g==0){
                    dp[r][c]=1;
                }else if(g==1){
                    dp[r][c]=2;
                }else{
                    int ch1 = s[r];
                    int ch2 = s[c];
                    
                    if(ch1!=ch2){
                        dp[r][c] = (dp[r][c-1]+dp[r+1][c] - dp[r+1][c-1] + mod)%mod;
                    }else{
                        int ni = next[r];
                        int pi = prev[c];

                        if(ni>pi){
                            dp[r][c]= (2*dp[r+1][c-1]+2 + mod)%mod;
                        }else if(ni==pi){
                            dp[r][c]=(2*dp[r+1][c-1]+1 + mod)%mod;
                        }else{
                            dp[r][c]=(2*dp[r+1][c-1]-dp[ni+1][pi-1] + mod)%mod;
                        }
                    }
                }
            }
        }
        
        
        return dp[0][n-1];
    }
};