class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>index;
        stack<int>br;
        
        index.push(-1);
        int ans =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                br.push('(');
                index.push(i);
            }else {
                if(!br.empty()){
                    index.pop();
                    br.pop();
                    ans = max(ans, i-index.top());
                }else{
                    index.push(i);
                }
            }
        }
        return ans;
    }
};