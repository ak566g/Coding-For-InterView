class Solution {
public:
    
    unordered_map<string, bool>dp;
    
    bool isPresent(string &s, vector<string>& wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(s==wordDict[i]){
                return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        if(s.size()==0){
            return true;
        }
        
        if(dp.count(s)>0){
            return dp[s];
        }
        
        bool ans = false;
        for(int i=0;i<s.size();i++){
            string temp = s.substr(0,i+1);
            
            if(isPresent(temp, wordDict)){
                ans = ans ||  wordBreak(s.substr(i+1), wordDict);
            }
        }
        return dp[s] = ans;
    }
};