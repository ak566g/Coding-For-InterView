//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        float u, v, a, s;
        cin>>u>>v>>a>>s;

        float minV;

        if(u*u<2*a*s){
            cout<<"YES";
        }
        else{
            minV = pow((u*u-2*a*s), 0.5);

            if(minV<=v){
                cout<<"YES";
            }else{
                cout<<"NO";
            }
        }
        cout<<"\n";
    }
}