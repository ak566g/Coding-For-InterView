class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n+1][n+1];
        pair<int, int>p;
        for(int g=0;g<n;g++){
            for(int i=0, j=g; i<n && j<n; i++, j++){
                if(g==0){
                    dp[i][j]=1;
                }else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=0;
                    }
                }else{
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                if(dp[i][j]){
                    p={i,j};
                }
            }
        }
        
        int start = p.first;
        int len = p.second - p.first+1;
        
        return s.substr(start, len);
    }
};