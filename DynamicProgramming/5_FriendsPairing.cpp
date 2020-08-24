//by Ankita Gupta

// Friends Pairing Problem 
// Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. 
// Find out the total number of ways in which friends can remain single or can be paired up.

// Examples:

// Input  : n = 3
// Output : 4
// Explanation
// {1}, {2}, {3} : all single
// {1}, {2,3} : 2 and 3 paired but 1 is single.
// {1,2}, {3} : 1 and 2 are paired but 3 is single.
// {1,3}, {2} : 1 and 3 are paired but 2 is single.
// Note that {1,2} and {2,1} are considered same.



#include<bits/stdc++.h>
using namespace std;
int mod=1000000007;

int numberOfWays(int n)
{
    // if(n<=1)
    // return 1;
    
    
    // int ans1=numberOfWays(n-1);
    // int ans2=(n-1)*numberOfWays(n-2);
    
    // return ans1+ans2;
    
    long long dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        long long ans1=dp[i-1]%mod;
        long long ans2=((i-1)*dp[i-2])%mod;
        dp[i]=(ans1+ans2)%mod;
    }
    
    return dp[n]%mod;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<numberOfWays(n)<<"\n";
	}
	
	return 0;
}