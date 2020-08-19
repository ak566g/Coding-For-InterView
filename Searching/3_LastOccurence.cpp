//by Ankita Gupta

// Given a sorted array with repeated elements, find the last occurence of given element
#include<bits/stdc++.h>
using namespace std;


int lastOccurence(int *a, int n , int element)
{
    int start=0;
    int end = n-1;
    int ans=-1;
    
    while(start<=end)
    {
        int mid = start + (end - start)/2;

        if(a[mid]==element)
        {
            ans = mid;
            start = mid+1;
        }
        else if(a[mid]<element)
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
        
    }

    return ans;
}

int main(){
    
    int n;
    cin>>n;

    int *a = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int element;
    cin>>element;

    cout<<lastOccurence(a,n,element);
}