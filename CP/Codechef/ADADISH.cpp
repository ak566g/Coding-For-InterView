//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int a[4]={0};
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int ans=0;
        for(int i=0;i<2;i++)

        {
            int temp;
            sort(a,a+4);
            temp=min(a[2],a[3]);
            a[2]-=temp;
            a[3]-=temp;
            ans+=temp;
        }        
        sort(a,a+4);
        ans+=a[3];

        cout<<ans<<"\n";

    }
}