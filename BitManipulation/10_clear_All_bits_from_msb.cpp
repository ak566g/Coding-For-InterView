//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int clearedMSB(int n, int i)
{
    int mask=(1<<i)-1;
    return n&mask;
}

int main(){
    int n,i;
    cin>>n>>i;

    cout<<clearedMSB(n,i);
}