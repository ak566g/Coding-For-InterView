// first String + secondString - LCS

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        
        int dp[m+1][n+1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        string ans = "";
        
        int i = m, j = n;
        
        while(i>=1 && j>=1){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }else{
                
                if(dp[i-1][j] > dp[i][j-1]){
                        ans += str1[i-1];
                        i--;
                }else{
                        ans += str2[j-1];
                        j--;
                }
            }
        }
        
        while(i>=1){
            ans += str1[i-1];
            i--;
        }
        
        while(j>=1){
            ans += str2[j-1];
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};