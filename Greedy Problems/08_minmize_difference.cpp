//by Ankita Gupta

// Problem discussion
// Harshit gave Aahad an array of size N and asked to minimize the difference between the 
// maximum value and minimum value by modifying the array under the condition that each 
// array element either increase or decrease by k(only once).

#include<bits/stdc++.h>
using namespace std;
int main() {

    int n, k;
    cin>>n>>k;
    
    int *a = new int[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    sort(a,a+n);
    int small= a[0];
    int large= a[n-1];
    
    small+=k;
    large-=k;
    
    if(small>large)
    {
        swap(small,large);
    }
    
    for(int i=1;i<n-1;i++)
    {
        int add= a[i]+k;
        int sub= a[i]-k;
        
        if(sub>=small || add <= large)
            continue;
        
        if((small-sub)<(add-large)){
            large=sub;
        }
        else{
            small=add;
        }
        
        if(small>large)
            swap(small,large);
    }
    
    cout<<min(a[n-1]-a[0],large-small);
	
}