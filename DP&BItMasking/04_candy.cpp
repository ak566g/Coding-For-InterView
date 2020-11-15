//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#define MAXN 16
#define ll long long
ll countSetBit(ll n)
{
    ll count=0;
    while(n>0)
    {
        if(n%2==1)
        {
        	count++;
        }
        n=n/2;
    }
    
    return count;
}


long long solve(int like[][MAXN],int N)
{
    ll dp[1<<N];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(ll mask = 0; mask < ((1<<N)-1);mask++)
    {
        ll count=countSetBit(mask);
        
        for(ll i=0; i<N; i++)
        {
            if((mask&(1<<i))==0 && like[count][i]==1)
            {
                dp[mask|(1<<i)]+=dp[mask];
            }
        }
    }
    return dp[(1<<N)-1];
}

int main()
{
	int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	cout<<solve(like,n)<<endl;
}