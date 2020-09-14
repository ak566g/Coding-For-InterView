//by Ankita Gupta

// Loot Houses
// A thief wants to loot houses. 
// He knows the amount of money in each house. 
// He cannot loot two consecutive houses. 
// Find the maximum amount of money he can loot.

#include<bits/stdc++.h>
using namespace std;

int getMaxMoney(int arr[], int n){
	int dp[n+1];
    dp[0]=0;
    dp[1]=arr[0];
    
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],arr[i-1]+dp[i-2]);
    }
    
    return dp[n];
}


int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}

