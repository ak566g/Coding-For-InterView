//by Ankita Gupta

// Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, 
// i.e., arr[i] may be present at arr[i+1] or arr[i-1]. 
// Write an efficient function to search an element in this array. 
// Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

// int find_in_nearly_sorted(int *a, int n, int key)
// {
//     int start = 0;
//     int end = n-1;

//     while(start<=end)
//     {
//         int mid = start + (end - start) /2;

//         if(mid>=1 && mid<= n-2)
//         {
//             if(a[mid+1]==key)
//             return mid+1;

//             if (a[mid-1]==key)
//             return mid-1;

//             if(a[mid]==key)
//             return mid;

//             else if(a[mid-1]>key)
//             {
//                 end = mid-2;
//             }
//             else
//             {
//                 start = mid +2;
//             }
//         }

//         else if(mid==0)
//         {
//             if(a[mid+1]==key)
//             return mid+1;

//             else if(a[mid]==key)
//             return mid;

//             else 
//             {
//                 start = mid +2;
//             }
//         }
//         else if (mid ==n-1)
//         {
//             if(a[mid]==key)
//             return mid;

//             else if(a[mid-1]==key)
//             return mid-1;

//             else 
//             end = mid -2;
//         }
//     }

//     return -1;
// }


// Recursive solution 
 int find(int *a,int start, int end, int key)
{
    if(start<=end)
    {
        int mid = start + (end - start)/2;

        if(a[mid]==key)
        return mid;

        if(mid>start&&a[mid-1]==key)
        return mid-1;

        if(mid<end && a[mid+1]==key)
        return mid+1;

        if(a[mid]>key)
        return find(a, start, mid-2 , key);

        return find(a, mid+2, end, key);
    }
}


int find_in_nearly_sorted(int *a, int n, int key)
{
    return find(a,0,n-1,key);
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

    cout<<find_in_nearly_sorted(a,n,key);
}
