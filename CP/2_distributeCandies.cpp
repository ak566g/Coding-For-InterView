//by Ankita Gupta

// Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). 
// Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
// 1. All students get equal number of candies.
// 2. All the candies which a student get must be from a single box only.
// As he want to make all of them happy so he want to give as many candies as possible. 
// Help Shaky in finding out what is the maximum number of candies which a student can get.

//This question is based on concept Binary Search on answer

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isValid(ll *a, int n, ll k, ll mid)
{
    ll count=0;
    ll sum=0;
    
    for(int i=0;i<n;)
    {
        count++;
        sum+=mid;
        if(sum>a[i])
        {
            sum=0;
            i++;
        	count--;
        }
        
    }
    
    if(count>=k)
        return true;
    
    return false;
}


ll candies(ll *a, int n, ll k)
{
    ll start=0;
    ll end=0;
    
    for(int i=0;i<n;i++){
        end= max(end,a[i]);
    }
    
    ll candies=0;
    
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        
        if(isValid(a,n,k,mid))
        {
            candies=max(candies,mid);
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    
    return candies;
}

int main() {
	int t;
    cin>>t;
    while(t--)
    {
    	int n;
        ll k;
        cin>>n>>k;
        
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout<<candies(a,n,k)<<"\n";
    }
    
}