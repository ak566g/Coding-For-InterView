//by Ankita Gupta

//An element is called peak element if it is greater than or equal to it's both of the neighbour.
#include<bits/stdc++.h>
using namespace std;

int peakElement(int a[], int n)
{

   int start =0;
   int end = n-1;
   
   while(start<=end)
   {
       int mid = start + (end - start)/2;
       if(mid>=1&&mid<=n-2)
       {
           if(a[mid]>=a[mid-1]&&a[mid]>=a[mid+1])
           return mid;
           else if(a[mid-1]>a[mid])
           end=mid-1;
           else
           start = mid+1;
       }
       else if(mid==0)
       {
           if(a[mid]>=a[mid+1])
           return mid;
           else
           {
               start=mid+1;
           }
       }
       else if(mid==n-1)
       {
           if(a[mid]>=a[mid-1])
           return mid;
           else 
           end=mid-1;
       }
       
       
       
   }
   
}

int main(){

     int n;
    cin>>n;

    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<peakElement(a,n);

}