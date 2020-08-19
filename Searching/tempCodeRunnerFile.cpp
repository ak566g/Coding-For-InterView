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