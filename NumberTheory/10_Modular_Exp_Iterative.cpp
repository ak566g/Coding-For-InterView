//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int modExp(int a, int b, int c)
{
    int ans =1;
    a = a%c;

    if(a==0)
    {
        return 0;
    }

    if(b==1)
    {
        return a;
    }

    while(b>0)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        b=b>>1;
        a = (a*a)%c;
    }

    return ans;
}


int main(){
    int a, b, c;
    cin>>a>>b>>c;

    cout<<modExp(a,b,c);
}