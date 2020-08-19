//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int findElement(int *a , int n, int key)
{

    int start = 0, end = n-1;
    
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        
        if(a[mid]==key)
        return mid;
        
        if(a[start]<=a[mid] )
        {
            if(a[mid]>=key&& a[start]<=key)
            end = mid-1;
            else
            start= mid +1;
        }
        
        else 
        {
            if(a[mid]<=key &&a[end]>=key)
            {
                start = mid +1;
            }
            else 
            {
                end = mid-1;
            }
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

    int key;
    cin>>key;

    cout<<findElement(a,n,key);

}