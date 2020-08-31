//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int flipBit(int n, int i)
{
    int x=1;
    x=x<<i;

    return n^x;
}

int main(){
    int n, i;
    cin>>n>>i;

    cout<<flipBit(n,i);
}