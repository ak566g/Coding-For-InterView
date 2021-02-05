//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int divisor(int n){
    for(int i=10;i>=1;i--){
        if(n%i==0){
            return i;
        }
    }

    return 1;
}

int main(){
    
        int n;
        cin>>n;
        cout<<divisor(n)<<"\n";
}