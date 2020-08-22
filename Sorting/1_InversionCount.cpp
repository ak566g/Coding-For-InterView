//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;




ll mergeInversion(ll *a, int start, int mid, int end)
{
    int n1= mid-start+1;
    int n2= end-mid;
    ll count=0;
    
    ll left[n1];
    ll right[n2];
    
    for(int i=0;i<n1;i++){
        left[i]=a[start+i];
    }
    
    for(int i=0;i<n2;i++){
        right[i]=a[mid+i+1];
    }
    
    int i=0,j=0,k=start;
    
    while(i<n1&&j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k++]=left[i++];
        }
        else
        {
            a[k++]=right[j++];
            count+=(n1-i);
        }
    }
    
    while(i<n1)
    {
        a[k++]=left[i++];
    }
    
    while(j<n2)
    {
        a[k++]=right[j++];
    }
    
    return count;
}


ll inversions(ll *a, int start, int end)
{
    if(start<end){
        
        int mid=start + (end-start)/2;
        ll left = inversions(a,start,mid);
        ll right = inversions(a,mid+1,end);
        ll mergeCount = mergeInversion(a,start,mid,end);
        return left + mergeCount+ right;
        
    }
    
    return 0;
}



long long getInversions(long long *arr, int n)
{
    return inversions(arr,0,n-1);
}

int main()
{
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}