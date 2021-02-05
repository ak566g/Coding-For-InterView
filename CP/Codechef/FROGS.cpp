//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int w[n], l[n];

        for(int i=0;i<n;i++){
            cin>>w[i];
        }

        for(int i=0;i<n;i++){
            cin>>l[i];
        }

        if(w[0]>w[1] && l[0]==1){
            cout<<2<<"\n";
        }
        else if(w[0]>w[1]){
            cout<<1<<"\n";
        }
        else{
            cout<<0<<"\n";
        }
    }

}