class Solution {
public:
    
    vector<string>ans;
    unordered_map<string, bool>um;
    unordered_map<string, bool>dp;
    
    bool helper(string word){
        if(word.size()<=0){
            return false;
        }
        
        if(dp.count(word)>0){
            return dp[word];
        }
        
        
        for(int i=0;i<word.size();i++){
            string prefix = word.substr(0, i+1);
            string suffix = word.substr(i+1);
            
            if(um[prefix] && (um[suffix] || helper(suffix))){
                return dp[word] = true;
            }
        }
        
        return dp[word] = false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto w : words){
            um[w]=true;
        }
        
        for(auto w : words){
            um[w]=false;
            
            if(helper(w)){
                ans.push_back(w);
            }
            
            um[w]=true;
        }
        
        return ans;
    }
};