//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int numofAP(int *a, int n){
    int mod = 100001;
    int ans=n+1;
    int count[1001];
    int dp[n];
    
    int minEle = a[0];
    int maxEle = a[0];
    
    for(int i=0; i<n; i++)
    {
        minEle = min(a[i], minEle);
        maxEle = max(a[i], maxEle);
    }
    
    for(int d=(minEle - maxEle); d<=(maxEle-minEle); d++)
    {
        memset(count, 0, sizeof(count));
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            
            if(a[i]-d>=1 && a[i]-d<=1000)
            {
                dp[i]=(dp[i]+count[a[i]-d])%mod;
            }
            ans=(ans+dp[i]-1)%mod;
            count[a[i]]=(count[a[i]]+dp[i])%mod;
        }
    }
    return ans;
}


int main(){

    int N;
    cin >> N;

    int *arr = new int[N+1];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << numofAP(arr, N) << endl;

    return 0;
}
