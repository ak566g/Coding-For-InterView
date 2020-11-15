//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int dp[51][51][51];
int helper(string a,string b,string c)
{
    int mod = (int)pow(10,9)+7;
	if(c.size()==0)
    {
        return 1;
    }
    
    if(a.size()==0 && b.size()==0)
    {
        return 0;
    }
    
    if(dp[a.size()][b.size()][c.size()]!=-1)
    {
        return dp[a.size()][b.size()][c.size()];
    }
    
    int ans=0;
    
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==c[0])
        {
            ans=(ans+helper(a.substr(i+1), b, c.substr(1)))%mod;
        }
    }
    
    
    for(int i=0; i<b.size(); i++)
    {
        if(b[i]==c[0])
        {
            ans=(ans+helper(a, b.substr(i+1), c.substr(1)))%mod;
        }
    }
    
    dp[a.size()][b.size()][c.size()]= ans;
    return ans;
}

int solve(string a,string b,string c)
{
    for(int i=0;i<51;i++)
    {
        for(int j=0;j<51;j++)
        {
            for(int k=0;k<51;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    
    return helper(a,b,c);
}

int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c)<<endl;
}