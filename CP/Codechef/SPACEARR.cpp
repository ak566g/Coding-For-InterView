//by Ankita Gupta

#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        int a[n+1];

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        sort(a+1, a+n+1);
        int inc = 0;
        bool ans = true;
        for(int i=1;i<=n;i++){
            int tempInc = i-a[i];
            if(tempInc<0){
                ans = false;
                break;
            }
            inc += tempInc;
        }

        if(!ans){
            cout<<"Second";
        }else if(inc%2 == 1){
            cout<<"First";
        }else{
            cout<<"Second";
        }

        cout<<"\n";
    }
}