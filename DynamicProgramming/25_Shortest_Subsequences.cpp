//by Ankita Gupta

#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;

int dp[1001][1001];

int helper(string s, string v)
{
    if(s.size()==0)
    {
        return INT_MAX-1;
    }
    
    if(v.size()==0)
    {
        return 1;
    }
    
    if(dp[s.size()][v.size()]!=-1)
        return dp[s.size()][v.size()];
    
    
    int i=0;
    for(i=0;i<v.size();i++){
        if(s[0]==v[i])
            break;
    }
    
    if(i==v.size())
        return 1;
    
    int ans1= helper(s.substr(1),v);
    int ans2= 1 + helper(s.substr(1),v.substr(i+1));
    
    dp[s.size()][v.size()] = min(ans1,ans2);
    return dp[s.size()][v.size()];
}


int solve(string s, string v)
{
	memset(dp,-1,sizeof(dp));
    return helper(s,v);
}

int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}