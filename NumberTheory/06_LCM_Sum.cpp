//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;
 

void func(long long n)
{
	ll etf[n+1], ans[n+1];
    memset(ans, 0, sizeof(ans));
    
    for(ll i=0;i<=n;i++){
        etf[i]=i;
    }
    
    for(ll i=2;i<=n;i++)
    {
        if(etf[i]==i)
        {
            etf[i]=i-1;
            
            for(ll j=i*2;j<=n;j+=i)
            {
                etf[j]= (etf[j]*(i-1))/i;
            }
        }
    }
    
    
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j+=i)
        {
            ans[j]+=(i*etf[i]);
        }
    }
    
    ll result = (ans[n]+1)*n;
    
    cout<<result/2;
}

int main()
{ 
    long long n;
    scanf ( "%lld", &n );
	func(n);
    return 0;
}
