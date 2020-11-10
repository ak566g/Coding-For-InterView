// https://www.spoj.com/problems/INCSEQ/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll bit[52][100001];
ll mod = 5000000;

void update(ll index, ll count, ll k)
{
    for( ; index <= 100000 ;index += (index & (-index)))
    {
        bit[k][index]+=count;
    }
}


ll query(ll index, ll k)
{
    ll count = 0;
    
    for(; index>0; index -= (index & (-index)))
    {
        count = (count + bit[k][index])%mod;
    }
    return count;
}

ll main()
{
    ll n, k;
    memset(bit, 0, sizeof(bit));
    cin>>n>>k;
    
    ll *a = new ll[n+1];
    ll *temp = new ll[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        temp[i]=a[i];
    }
    
    unordered_map<ll, ll>mp;
    sort(temp+1, temp+n+1);
    
    ll index=1;
    for(ll i=1;i<=n;i++)
    {
        if(mp.count(temp[i])==0)
        {
            mp[temp[i]]=index;
            index++;
        }
    }
    
    for(ll i=1;i<=n;i++)
    {
        a[i]=mp[a[i]];
    }
    
    ll ans=0;
    
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=k;j++)
        {
            ll count =0;
            if(j==1)
            {
                count=1;
            }
            else
            {
                count = query(a[i]-1, j-1);
            }
            
            update(a[i], count, j);
            
            if(j==k)
            {
                ans = (ans + count)%mod;
            }
        }
    }
    
    cout<<ans;
    
    return 0;
}
