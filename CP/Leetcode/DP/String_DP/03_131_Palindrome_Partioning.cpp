class Solution {
public:
    
    vector<vector<string>>ans;
    
    bool isPalindrome(string s){
        string temp=s;
        reverse(temp.begin(), temp.end());
        
        return s==temp;
    }
    
    void helper(string s, vector<string>v){
        if(s.size()==0){
            ans.push_back(v);
            return;
        }
        
        for(int i=0;i<s.size();i++){
            if(isPalindrome(s.substr(0,i+1))){
                v.push_back(s.substr(0,i+1));
                helper(s.substr(i+1), v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {   
        vector<string>v;
        helper(s,v);
        return ans;
    }
};