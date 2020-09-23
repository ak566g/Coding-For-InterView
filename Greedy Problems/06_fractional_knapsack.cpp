//by Ankita Gupta
//Problem Link
//https://dmoj.ca/problem/coci13c1p4

#include<bits/stdc++.h>
#define ll long long
using namespace std;

class jewellery{
    public:
    int m;
    int v;
};

bool cmp(jewellery &j1, jewellery &j2)
{
    if(j1.v!=j2.v)
    return j1.v > j2.v;

    return j1.m < j2.m;
}

int main(){
    int n;
    int k;
    cin>>n>>k;

    jewellery j[n];
    for(int i=0;i<n;i++)
    {
        cin>>j[i].m>>j[i].v;
    }

    sort(j,j+n,cmp);

    multiset< int >bags;

    while(k--)
    {
        int x;
        cin>>x;
        bags.insert(x);
    }

    ll ans=0;

    for(int i=0;i<n;i++)
    {
        if(bags.empty())
        break;


        if(bags.lower_bound(j[i].m)!=bags.end())
        {
            ans+=j[i].v;
            bags.erase(bags.lower_bound(j[i].m));
        }
    }

    cout<<ans;
}