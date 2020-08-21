//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int floorIndex(ll *a , int n, ll key)
{
    int start= 0;
    int end= n-1;
    
    int ans=-1;
    
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        
        if(a[mid]==key)
        {
            return mid;
        }
        
        else if(a[mid]<key)
        {
            ans=mid;
            start = mid+1;
        }
        else
        {
            end =mid-1;
        }
    }
    
    return ans;
}



int main(){
        
    int n;
	cin>>n;
	    
	ll *a = new ll[n];
	ll key;
	cin>>key;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	    
	cout<<floorIndex(a,n,key)<<"\n";
}