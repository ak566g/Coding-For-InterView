//by Ankita Gupta

#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
    	string s;
        cin>>s;
        int index[256];
        memset(index,-1,sizeof(index));
        long long dp[s.size()+1];
        
        dp[0]=1;
        
        for(int i=1;i<=s.size();i++)
        {
            dp[i]=(2*dp[i-1])%mod;
            if(index[s[i-1]]!=-1)
            {
                //+ mod for safety.. try to add always.
                // otherwise if later is greater than earlier it will give wrong answer.
                dp[i]=(dp[i]-dp[index[s[i-1]]]+mod)%mod;
            }
            index[s[i-1]]=(i-1);
        }
        
        cout<<dp[s.size()]%mod<<"\n";
    }
    
    return 0;
}
