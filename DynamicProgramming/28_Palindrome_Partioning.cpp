// Initial Template for c++

// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    int dp[502][502];
    
    bool isPalindrom(string str, int i, int j){
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    
    int helper(string s, int start, int end){
        
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        
        if(start>=end){
            return 0;
        }
        
        if(isPalindrom(s, start, end)){
            return 0;
        }
        
        int ans = INT_MAX-1;
        for(int k=start;k<=end-1;k++){
            
            if(isPalindrom(s, start,k)){
                int left = helper(s, start, k);
                int right = helper(s, k+1, end);
                
                ans = min(ans, 1+left+right);
            }
        }
        dp[start][end]=ans;
        return ans;
    }

    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        return helper(str, 0, str.size()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends