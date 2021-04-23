// variation of longest increasing subsequence.

class Solution {
public:
    
    static bool cmp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    
    bool isValid(string &s1, string &s2){
        if((s2.size()-s1.size())!=1){
            return false;
        }
        
        int j = 0;
        
        for(int i=0;i<s2.size();i++){
            if(j<s1.size() &&  s1[j] == s2[i]){
                j++;
            }
        }
        
        return j == s1.size();
    }
    
    int helper(vector<string>& words){
        int n = words.size();
        int dp[n];
        dp[0]=1;
        int ans = 1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j = i-1; j>=0; j--){
                if(isValid(words[j], words[i])){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        return helper(words);
    }
};