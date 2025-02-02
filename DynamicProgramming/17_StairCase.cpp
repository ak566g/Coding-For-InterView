//by Ankita Gupta

// StairCase Problem

// A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. 
// Implement a method to count how many possible ways the child can run up to the stairs. 
// You need to return all possible number of ways.


#include<bits/stdc++.h>
using namespace std;


long long staircase(int n)
{
	long long dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
