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
                return ans;
            }
            else if(a[mid-1]>a[mid])
            {
                end=mid-1;
            }
            else
            {
                start= mid+1;
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

int main()
 {
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
	    
	    cout<<bitonicPoint(a,n)<<"\n";
	}
	
	return 0;
}