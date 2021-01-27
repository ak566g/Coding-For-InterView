#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

#define ll long long


ll merge(ll *arr, ll start, ll mid, ll end)
{
    ll n1 = mid-start+1;
    ll n2 = end-mid;
    
    ll *left = new ll[n1];
    ll *right = new ll[n2];
    
    for(ll i = 0; i<n1; i++){
        left[i] = arr[start+i];
    }
    
    for(ll i = 0; i<n2; i++){
        right[i] = arr[mid+i+1];
    }
    
    ll count = 0;
    
    ll i = 0, j = 0, k = start;
    
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
        }
        else{
            count += (n1-i);
            arr[k++]=right[j++];
        }
    }
    
    while(i<n1){
        arr[k++]=left[i++];
    }
    
    while(j<n2){
        arr[k++]=right[j++];
    }
    
    return count;
}


ll mergeSort(ll *arr, ll start, ll end)
{
    if(start>=end){
        return 0;
    }
    
    ll mid = start + (end - start)/2;
    
    ll left = mergeSort(arr, start, mid);
    ll right = mergeSort(arr, mid+1, end);
    
    ll mergeCount = merge(arr, start, mid, end);
    
    return left+right+mergeCount;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr, 0, N-1);
}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends