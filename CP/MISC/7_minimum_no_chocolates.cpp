//by Ankita Gupta

// Minimum Number of Chocolates

// Noor is a teacher. She wants to give some chocolates to the students in her class. 
// All the students sit in a line and each of them has a score according to performance. 
// Noor wants to give at least 1 chocolate to each student. 
// She distributes chocolates to them such that If two students sit next to each other then the one with the higher score must get more chocolates. 
// Noor wants to save money, so she wants to minimise the total number of chocolates.
// Note that when two students have equal score they are allowed to have different number of chocolates.

#include<bits/stdc++.h>
using namespace std;

int getMin(int *arr, int n){
	int dp[n];
    memset(dp,0,sizeof(dp));
    
    dp[0]=1;
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
            dp[i]=dp[i-1]+1;
   		else
            dp[i]=1;
    }
    
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1] && dp[i]<=dp[i+1])
			dp[i]=1+dp[i+1];
    }
    
    int sum=0;
    
    for(int i=0;i<n;i++)
        sum+=dp[i];
    
    return sum;
}

int main(){

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << getMin(arr, n);
    delete []arr;
}
