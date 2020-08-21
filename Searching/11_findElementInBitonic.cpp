//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
int bitonicPoint(int *a, int n)
{
    int start =0 , end = n-1;
    int ans=-1;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        
        if(mid>=1&&mid<=n-2)
        {
            if(a[mid]>a[mid-1]&&a[mid]>a[mid+1])
            {
                return mid;
            }
            else if(a[mid-1]<a[mid]&& a[mid]<a[mid+1])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        else if(mid==0)
        {
            if(a[mid+1]<a[mid])
            return mid;
            else
            start =mid+1;
        }
        else if(mid==n-1)
        {
            if(a[mid-1]<a[mid])
            return mid;
            else
            end=mid-1;
        }
    }
    
    return ans;
}

int binarySearchAs(int *a, int start, int end, int key)
{
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(a[mid]==key)
        return mid;
        else if(a[mid]<key)
        start =mid+1;
        else
        end=mid-1;
        
    }
    return -1;
}


int binarySearchDs(int *a, int start, int end, int key)
{
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(a[mid]==key)
        return mid;
        else if(a[mid]<key)
        end=mid-1;
        else
        start=mid+1;
        
    }
    return -1;
}


int bitonicPoint(int *a, int n,int key)
{
   int btp= bitonicPoint(a,n);
   //cout<<btp<<"\n";
   int ans1=binarySearchAs(a,0,btp,key);
   if(ans1==-1)
    return binarySearchDs(a,btp+1, n-1,key);
   
   return ans1;
   
   
   
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int *a = new int[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    int key;
	    cin>>key;
	    
	    cout<<bitonicPoint(a,n,key)<<"\n";
	}
	
	return 0;
}