//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll count=0;

    for(int i=0;i<n;i++)
    {
        ll sum=0;
        for(int j=0;j<k;j++)
        {
            ll cur;
            cin>>cur;
            sum+=cur;
        }

        ll asked;
        cin>>asked;
        if(asked<=10 && sum>=m)
        count++;
    }

    cout<<count;
}