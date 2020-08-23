#include<bits/stdc++.h>
#define ll long long
using namespace std;



void init(ll *three)
{
    for(int i=0;i<=37;i++){
        three[i]=(ll)(pow(3,i));
    }
}


ll check(ll n, ll ans, ll *three,int size)
{
    if(n<=0)
    {
        return -1;
    }

    else if(size==0)
    {
        return ans;
    }
    
    ans= check(n-three[0],ans+three[0],three+1, size-1);
    ans= check(n,ans,three+1,size-1);

    return ans;
}

int main()
{
    ll three[38];
    init(three);

    // cout<<(pow(3,38)<=pow(10,18))<<"\n";

    // for(int i=0;i<=37;i++){
    //     cout<<three[i]<<" ";
    // }


    ll n;
    cin>>n;
    ll ans=0;
    cout<<check(n,ans,three, 38);

}