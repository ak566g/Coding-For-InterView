#include <bits/stdc++.h>
#define ll long long
using namespace std;


int dp[2001][2001];

// ll helper(vector<int>arr, int n, int w){
//     if(n<0){
//         return 0;
//     }
    
//     if(w<0){
//         return INT_MIN;
//     }
    
//     if(dp[n][w]!=-1){
//         return dp[n][w];
//     }
    
//     ll sum1 = arr[n] + helper(arr, n, w-arr[n]);
//     ll sum2 = helper(arr, n-1, w);
    
//     return dp[n][w] = max(sum1, sum2);
// }


ll helper(vector<int>arr, int n, int w){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }
            if(j>=arr[i-1]){
                dp[i][j] = max(dp[i-1][j] , arr[i-1]+dp[i][j-arr[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][w];
}


int unboundedKnapsack(int w, vector<int> arr) {
    memset(dp, -1, sizeof(dp));
    return helper(arr, arr.size(), w);
}

int main()
{
    int t;
    cin>>t;
    
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>arr(n);
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        cout<<unboundedKnapsack(k, arr)<<"\n";
    }   
}
