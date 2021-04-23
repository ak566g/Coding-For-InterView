class Solution {
public:
    
    int dp[2002][2002];
    
    bool isPalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    int helper(string &s, int start, int end){
        
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        
        if(start>=end){
            return 0;
        }
        
        if(isPalindrome(s, start, end)){
            return 0;
        }
        
        int ans = 10000;
        for(int i=start;i<end;i++){
            if(isPalindrome(s, start, i))
                ans = min(ans, 1+ helper(s, start, i) + helper(s, i+1, end));
        }
        
        return dp[start][end] = ans;
    }
    
    int minCut(string s) {
        memset(dp,-1, sizeof(dp));
        return helper(s, 0, s.size()-1);
    }
};