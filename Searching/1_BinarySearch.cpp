//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;


int binarySearch(int *a, int n , int element)
{
    int start=0;
    int end=n-1;

    while(start<=end)
    {
        int mid= start +(end-start)/2;

        if(a[mid]==element)
        return mid;
        else if(a[mid]<element)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        
    }

    return -1;
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


    cout<<binarySearch(a,n,element);
}