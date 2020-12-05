//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n, d;
        cin>>n>>d;
        int infected=0;

        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;

            if(x>=80 || x<=9)
            {
                infected++;
            }
        }

        int ans = ceil(infected*(1.0)/d);

        n = n-infected;

        ans+= ceil(n*(1.0)/d);

        cout<<ans<<"\n";
    }
}