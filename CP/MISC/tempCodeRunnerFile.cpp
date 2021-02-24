//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--)
    {
        int m, n;
        cin>>m>>n;

        int temp=m;
        ll ans=LLONG_MAX;
        ll *a = new ll[n];
        vector<ll>mini;

        while(m--){
            for(int i=0;i<n;i++)
            cin>>a[i];

            ll *dp= new ll[n+1];
            dp[0]=0;

            dp[1]=a[0];

            for(int i=2;i<=n;i++)
            {
                ll ans1= a[i-1]+dp[i-2];
                ll ans2= dp[i-1];

                dp[i]=max(ans1,ans2);
            }

            mini.push_back(dp[n]);
        }

        if(temp==1)
        ans=mini[0];
        else
        {
            

            if(temp==2)
            {
                sort(mini.begin(),mini.end());
                ans=mini[0];
            }
            else if(temp==3)
            {
                ans=min(a[0]+a[2],a[1]);
            }
            else
            {
                ans=min(a[0]+a[2],min(a[1]+a[3], a[0]+a[3]));
            }
            

        }
        

        cout<<ans<<"\n";
    }

}