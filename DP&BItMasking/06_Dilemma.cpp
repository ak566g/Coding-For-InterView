//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int dp[101][1<<11];

int helper(int pos, int mask, vector<string>v)
{
    if((mask&(mask-1))==0)
    {
        return 0;
    }
    
    if(pos<0)
    {
        return 100000;
    }
    
    if(dp[pos][mask]!=-1)
    {
        return dp[pos][mask];
    }
    
    int newmask1=0;
    int newmask2=0;
    int touches=0;
    
    for(int i=0;i<v.size();i++)
    {
        
        if((mask&(1<<i)))
        {
            touches++;
            if(v[i][pos]=='0')
            {
                newmask1 = newmask1|(1<<i);
            }
            else
            {
                newmask2 = newmask2|(1<<i);
            }
        }
    }
    
    int ans1 = helper(pos-1, newmask1, v)+ helper(pos-1, newmask2, v) + touches;
    int ans2 = helper(pos-1, mask, v);
    
    dp[pos][mask] = min(ans1, ans2);
    return dp[pos][mask];
}

int minimumTouchesRequired(int n, vector<string> v) {
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<(1<<11);j++)
        {
            dp[i][j]=-1;
        }
    }
    
    return helper(v[0].size()-1, (1<<n)-1, v);
}

int main() {
    int n;
    
    vector<string> v;
    
	cin >> n;
	for(int i = 0; i < n; i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}
	cout << minimumTouchesRequired(n, v) << endl;
}