class Solution {
public:
    
    int dp[105][105];
    
    bool helper(string &s1, string &s2, string &s3, int i, int j, int k){
        if(k==s3.size() && i==s1.size() && j==s2.size()){
            return true;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        bool ans1 = false, ans2=false;
        if(i<s1.size() && k<s3.size() && s1[i]==s3[k]){
            ans1 = helper(s1, s2, s3, i+1, j, k+1);
        }
        
        if(j<s2.size() && k<s3.size() && s2[j]==s3[k]){
            ans2 = helper(s1, s2, s3, i, j+1, k+1);
        }
        
        return dp[i][j] = ans1||ans2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return helper(s1,s2,s3,0,0,0);
    }
};