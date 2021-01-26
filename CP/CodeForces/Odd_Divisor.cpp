//by Ankita Gupta

#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

bool check(ull n){

    return n && (!(n&(n-1)));
}


int main(){
    int t;
    cin>>t;

    while(t--){
        ull n;
        cin>>n;

        if(n==1){
            cout<<"YES";
        }
        else if(check(n)){
            cout<<"NO";
        }
        else{
            cout<<"YES";
        }

        cout<<endl;
    }
}