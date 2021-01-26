//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        bool ans = false;
        for(int i=0;i*i<n;i++){
            for(int j=0;j*j<n;j++){
                if(i*2020+j*2021==n){
                    ans=true;
                    break;
                }
            }

            if(ans){
                break;
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