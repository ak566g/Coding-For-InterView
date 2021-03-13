//by Ankita Gupta


    // n number of people
    // e number of eggs
    // h number of chocolates
    // a cost of omelette
    // b cost of milkshake
    // c cost of cake

    // 2 eggs for omellete
    // 3 chocolates for milkshake
    // 1 egg 1 chocolate for cake

 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll colclf4(ll n, ll e, ll h, ll a, ll b, ll c){
    if(n<=0){
        return 0;
    }

    ll ans = 1e15;

    // all omellete
    if(e>=2*n){
        ans = min(ans, a*n);
    }

    // all milkshake
    if(h>=3*n){
        ans = min(ans, b*n);
    }

    // all cake
    if(n<=e && n<=h){
        ans = min(ans, c*n);
    }

    // milkshake and cake

    if((h-n)>=2 && (h-n)>=2*(n-e)){
        ll x;
        
        if(b<c){
            x = min(n-1, (h-1)/3);
            ans = min(ans, x*b + (n-x)*c);
        }else{
            
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        ll n, e, h, a, b, c;
        cin>>n>>e>>h>>a>>b>>c;

        
    }


}