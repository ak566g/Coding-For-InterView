//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        long long  sum =0;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            sum+=x;
        }

        if(sum%2==0){
            cout<<1;   
        }
        else{
            cout<<2;
        }
        cout<<"\n";
    }
}