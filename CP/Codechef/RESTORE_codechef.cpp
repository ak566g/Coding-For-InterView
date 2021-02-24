//by Ankita Gupta

#include<bits/stdc++.h>
#define  ll long long
#define max 10000000
using namespace std;

bool seive[max+1];
vector<int>prime;

void init()
{
    memset(seive, true, sizeof(seive));
    seive[0]=false;
    seive[1]=false;

    for(ll i=1; i<=max; i++)
    {
        if(seive[i]==true)
        {
            for(ll j=i+i; j<=max; j+=i)
            {
                seive[j]=false;
            }
        }
    }

    for(int i=2;i<=max;i++)
    {
        if(seive[i]==true)
        {
            prime.push_back(i);
        }
    }
}

int main(){
    init();   
    // cout<<prime.size(); 

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int *a= new int[n+1];

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        int *b = new int[n+1];

        int k=0;
        // for(int i=1; i<=n;i++)
        // {

        //     b[i]*=prime[k];
        //     if(a[i]!=i)
        //     b[a[i]]*=prime[k];
        //     k++;
        // }

        for(int i=1; i<=n; i++)
        {
            if(a[i]!=i)
            {
                b[i]=prime[a[i]-1];
            }
            else
            {
                b[i]=prime[i-1];
            }
            
        }


        for(int i=1;i<=n;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<endl;   
    }
}
