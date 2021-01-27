//by Ankita Gupta

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        
        int start = 0, end = n-1;
        int count = 0;
        while(start<end){
            if(arr[start] + arr[end] == k){
                int i=end;
                while(arr[i]==arr[end] && i>start){
                    count++;
                    i--;
                }
                start++;
            }
            
            else if(arr[start]+arr[end]<k){
                start++;
            }
            else{
                end--;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends