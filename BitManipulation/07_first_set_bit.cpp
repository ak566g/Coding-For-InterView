//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int firstSetBit(int n){
    return n&(n*-1);
}

int main(){

    int n;
    cin>>n;

    cout<<firstSetBit(n);
}