//by Ankita Gupta

#include<bits/stdc++.h>
#define mx INT_MAX
#define ll long long
using namespace std;

ll minCost(int n, int e, int h, int a, int b, int c){
    if(n==0){
        return 0;
    }

    ll cost1 = mx;
    ll cost2 = mx;
    ll cost3 = mx;

    // cake
    if(e>=1&& h>=1){
        cost1 = c+ minCost(n-1, e-1, h-1, a, b, c);
    }

    //omlette
    if(e>=2){
        cost2 = a + minCost(n-1, e-2, h, a, b, c);
    }

    // chocolate milkshake
    if(h>=3){
        cost3 = b + minCost(n-1, e, h-3, a, b, c);
    }

    // cout<<min(cost1, min(cost2, cost3))<<"\n";
    return min(cost1, min(cost2, cost3));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n, e, h, a, b, c;

        cin>>n>>e>>h>>a>>b>>c;

        ll ans = minCost(n, e, h, a, b, c);

        if(ans>=mx){
            cout<<-1;
        }else{
            cout<<ans;
        }

        cout<<"\n";
    }
}