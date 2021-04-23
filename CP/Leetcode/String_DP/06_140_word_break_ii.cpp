class Solution {
public:
    vector<string>ans;
    
    bool isPresent(string word, vector<string>&wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(wordDict[i]==word){
                return true;
            }
        }
        return false;
    }
    
    void helper(string s, vector<string>&wordDict, int cur, string temp){
        if(cur>=s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        int l=1;
        for(int i=cur; i<s.size(); i++, l++){
            string tempWord = s.substr(cur, l);
            // cout<<tempWord<<" ";
            if(isPresent(tempWord, wordDict)){
                helper(s, wordDict, i+1, temp+tempWord+" ");
            }
        }
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        helper(s, wordDict, 0, "");
        return ans;
    }
};