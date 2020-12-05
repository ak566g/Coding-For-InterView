//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;


int power(int x, int n)
{
    if(n==0)
    {
        return 1;
    }

    if(n%2==1)
    {
        return x * power(x, n/2)* power(x, n/2);
    }

    else
    {
        return power(x, n/2)* power(x, n/2);
    }
    
}

int main(){
    int x, n;
    cin>>x>>n;

    cout<<power(x,n);
}