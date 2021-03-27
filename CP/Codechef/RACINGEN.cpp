//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while (t--)
    {
        ll x, r, m;
        cin>>x>>r>>m;
        r=r*60;
        m=m*60;
        ll totalSec = 0;
        while(r>0){
            r-=x;
        }
        if(totalSec<=m){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<"\n";
    }
    
}