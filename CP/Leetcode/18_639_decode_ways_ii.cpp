class Solution {
public:
    int mod = pow(10,9)+7;
    
    int numDecodings(string s) 
    {
        long long dp[s.size()+1];
        memset(dp, 0, sizeof(dp));
        
        if(s[0]=='0'){
            return 0;
        }
        
        dp[0]=1;
        s="0"+s;
        
        if(s[1]=='*'){
            dp[1]=9;
        }else{
            dp[1]=1;
        }
        
        
        for(int i=2;i<s.size();i++)
        {
            // considering only current Character;
            if(s[i]=='*')
            {
                dp[i]+=(9*dp[i-1]);
            }
            else if(s[i]>='1' && s[i]<='9')
            {
                dp[i]+=dp[i-1];
            }
            
            // considering two chars
            
            if(s[i-1]=='*' && s[i]=='*')
            {
                dp[i]+=(dp[i-2]*15);
            }
            else if(s[i-1]=='*' && s[i]!='*')
            {
                if(s[i]>='0' && s[i]<='6'){
                    dp[i]+=(dp[i-2]*2);
                }
                else{
                    dp[i]+=dp[i-2];
                }
            }
            else if(s[i-1]!='*' && s[i]=='*')
            {
                if(s[i-1]=='1'){
                    dp[i]+=(dp[i-2]*9);
                }else if(s[i-1]=='2'){
                    dp[i]+=(dp[i-2]*6);
                }
            }
            else if(s[i-1]!='*' && s[i]!='*')
            {
                int n1 = s[i-1]-'0';
                int n2 = s[i]-'0';
                
                if((n1*10 + n2)>=10 && (n1*10 + n2)<=26){
                    dp[i]+=dp[i-2];
                }
            }
            dp[i]=dp[i]%mod;
        }
        return dp[s.size()-1];
    }
};