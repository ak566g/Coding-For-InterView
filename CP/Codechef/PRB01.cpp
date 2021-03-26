//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n==1){
        return false;
    }

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(isPrime(n)){
            cout<<"yes";
        }else{
            cout<<"no";
        }
        cout<<"\n";
    }
}