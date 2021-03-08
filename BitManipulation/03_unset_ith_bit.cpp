//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int unset(int n, int i)
{
    int x=1;
    x=x<<i;
    x=~x;

    return n&x;
}

int main(){
    
    int n, i;
    cin>>n>>i;

    cout>>unset(n,i);
}