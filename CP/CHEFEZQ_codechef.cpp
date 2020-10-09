//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int dayCount(int *q, int k, int n)
{
    int ans=0;
    int i=0;

    while(q[i]>=k && i<n-1)
    {
        //q[i]-=k;
        q[i+1]+=q[i];
        
        q[i]=0;
        i++;
        ans++;
    }

    if(q[i]<k)
    {
        return ans+1;
    }

    ans+=(q[i]/k)+1;

    return ans;
}

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;

        int q[n];

        for(int i=0;i<n;i++)
        {
            cin>>q[i];
        }

        cout<<dayCount(q,k,n)<<"\n";

    }
}