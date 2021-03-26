class Solution {
public:
    int numDecodings(string s) {
        int dp[s.size()+1];
        memset(dp, 0, sizeof(dp));
        
        if(s[0]=='0'){
            return 0;
        }
        
        dp[0]=1;
        
        for(int i=1;i<s.size();i++){
            int n2 = s[i]-'0';
            int n1 = s[i-1]-'0';
            
            if(n2>=1 && n2<=9){
                dp[i]+=dp[i-1];
            }
            
            if((n1*10 + n2)>=10&&(n1*10 + n2)<=26){
                if((i-2)>=0){
                    dp[i]+=dp[i-2];
                }else{
                    dp[i]+=1;
                }
            }
        }
        
        return dp[s.size()-1];
    }
};