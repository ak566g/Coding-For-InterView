//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        ll a[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        ll maxans = 0;
        sort(a,a+n);

        ll x  = a[0], y = a[n-1];

        for(int i=1;i<n-1;i++){
            ll currentans = abs(x-a[i]) + abs(a[i]-y) + abs(y-x);
            maxans = max(maxans, currentans);
        }
         
        cout<<maxans<<endl;
    }
}