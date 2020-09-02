//by Ankita Gupta
// Largest Bitonic Subarray

// You are given an array of positive integers as input. 
// Write a code to return the length of the largest such subsequence in 
// which the values are arranged first in strictly ascending order and then in strictly descending order.
// Such a subsequence is known as bitonic subsequence. 
// A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.


// Sample Input 1:
// 6
// 15 20 20 6 4 2
// Sample Output 1:
// 5


// This problem is slight variation of longest increasing subsequence.
#include<bits/stdc++.h>
using namespace std;


int longestBitonicSubsequence(int input[], int n)
{
    int lis[n];                                 //Longest Increasing Subsequence
    int lds[n];                                 //Longest Decreasing Subsequence

    lis[0]=1;

    for(int i=1;i<n;i++){
        lis[i]=1;

        for(int j=i-1;j>=0;j--){
            if(input[j]<input[i])
            {
                lis[i]=max(lis[i],1+lis[j]);
            }
        }
    }


    lds[n-1]=1;

    for(int i=n-2;i>=0i--){
        lds[i]=1;

        for(int j=i+1;j<n;j++)
        {
            if(input[j]<input[i])
            {
                lds[i]=max(lds[i],1+lds[j]);
            }
        }
    }

    int ans= lis[0]+lds[0]-1;

    for(int i=1;i<n;i++)
    {
        ans=max(ans,lis[i]+lds[i]-1);
    }

    return ans;
}


int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubsequence(input, n);
  return 0;
}
