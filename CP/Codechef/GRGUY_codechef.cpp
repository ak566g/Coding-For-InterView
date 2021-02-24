//by Ankita Gupta
//Tags- Greedy , DP

#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--)
    {
        string s1;
        string s2;

        cin>>s1>>s2;


        int n=s1.size();
        int dp[2][n];

        
        if(s1[0]=='.')
        dp[0][0]=0;
        else
        dp[0][0]=INT_MAX-1;

        if(s2[0]=='.')
        dp[1][0]=0;
        else
        dp[1][0]=INT_MAX-1;

        for(int i=1;i<n;i++)
        {
            if(s1[i]=='.')
            {
                int ans1=dp[0][i-1];
                int ans2=dp[1][i-1]+1;

                dp[0][i]=min(ans1,ans2);
            }
            else
            {
                dp[0][i]=INT_MAX-1;
            }
            

            if(s2[i]=='.')
            {
                int ans1=dp[0][i-1]+1;
                int ans2=dp[1][i-1];

                dp[1][i]=min(ans1,ans2);
            }
            else
            {
                dp[1][i]=INT_MAX-1;
            }

        }
        


        int ans=min(dp[0][n-1],dp[1][n-1]);

        if(ans==INT_MAX-1)
        cout<<"No";
        else
        {
            cout<<"Yes"<<"\n"<<ans;
        }

        cout<<"\n";
    }

}