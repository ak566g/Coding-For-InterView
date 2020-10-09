//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool cal(int n , int k, int x, int y)
{
    if(x==y)
    return true;

    int start=x;
    while(true)
    {

        if((start+k)%n==y)
        return true;

        if((start+k)%n==x)
        {
            return false;
        }

        start=(start+k)%n;
    }
    return false;
}

int main(){

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int k, x, y;
        cin>>k>>x>>y;

        if(cal(n,k,x,y))
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }

        cout<<endl;
      
    }

}