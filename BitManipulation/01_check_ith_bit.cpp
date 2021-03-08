//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i;
    cin>>n>>i;

    if(n&(1<<i)){
        cout<<"Set";
    }
    else{
        cout<<"Unset";
    }
}