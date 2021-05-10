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
        int a, b;
        cin>>a>>b;

        ll z = 2*a*b;

        ll x = 0;
        ll y = 0;

        for(int i=1;i<2*b;i++){
            ll tempx = i*a;
            ll tempy = (2*b-i)*a;

            if(tempx!=tempy){
                x = tempx;
                y = tempy;
                break;
            }
        }
        
        if(x!=0 && y!=0 && z!=0){
            cout<<"YES\n";
            cout<<x<<" "<<y<<" "<<z<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
    
}