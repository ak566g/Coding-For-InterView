//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

// Do not handle duplicate elements
// int rotations(int *a, int n)
// {
//     int left = 0, right = n-1;  

//     while(left<=right)
//     {
//         int mid = left + (right - left)/2;
//         int l = (mid + n -1)%n;
//         int r = (mid + 1 )%n;

//         if(a[mid]<a[l] && a[mid]<a[r])
//         return mid;

//         else if(a[mid]<a[right])
//         {
//             right = mid-1;
//         }
//         else 
//         {
//             left = mid + 1;
//         }
//     }
// }

// Handles duplicates also 
int rotations(int *a, int start, int end, int n)
{
    if(start<=end)
    {
        int mid = start + (end - start)/2;

        if(mid+1 < n && a[mid+1]<a[mid])
        return mid +1 ;
        
        if(mid-1>=0&& a[mid]<a[mid-1])
        return mid;
        
        if(a[mid]<a[end])
        {
            return rotations(a,start, mid-1, n);
        }
        else if(a[mid]>a[end])
        {
            return rotations(a,mid+1, end,n);
        }
        else 
        {
            int res1 = rotations(a,start,mid-1,n);
            int res2 = rotations(a, mid+1,end,n);

            if(res1 == 0)
            return res2;
            
            return res1;
        }
        
    }
    return 0;
}


int main(){

    int n;
    cin>>n;

    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<rotations(a,0,n-1, n);
}