//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool powerOfTwo(int n){
    if(n==1)
    return true;

    return n&&!(n&(n-1));
}


int main(){
    int n;
    cin>>n;

    cout<<powerOfTwo(n);
}