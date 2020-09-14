//by Ankita Gupta

// Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . 
// In this game there are N integers on a board. 
// In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .
// This move will give him x points.
// He plays the game until the board becomes empty .
// But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . 
// Can you help Gary in finding out the maximum points he receive grab from the game ?



#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>A;

int solve(int n,vector<int>A){
	int hashmap[1001]={0};
    int dp[1001]={0};
    for(int i=0;i<A.size();i++)
    {
        hashmap[A[i]]++;
    }
    
    dp[0]=0;
    dp[1]=hashmap[1];
    
    for(int i=2;i<=1000;i++){
    	dp[i]=max(dp[i-1],dp[i-2]+i*hashmap[i]);
    }
        
    return dp[1000];
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}