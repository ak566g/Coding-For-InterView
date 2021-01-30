//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int dp[n];

        for(int i=0;i<n;i++){
            dp[i]=0;
        }

        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(s[i]>=s[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
        }

        int maxnum =0;

        for(int i = 0; i<n ;i++){
            maxnum = max(dp[i], maxnum);
        }    

        cout<<n-maxnum<<"\n";
    }
}