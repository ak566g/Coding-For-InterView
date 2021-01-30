//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int powertwo(int n){


    while(n%2==0){
        n=n/2;
    }
    
    return n;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;
        k = powertwo(k);

        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool ans = true;
        for(int i=0;i<n;i++){
            if(a[i]%k!=0){
                ans = false;
            }
        }

        if(ans){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}