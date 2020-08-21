//by Ankita Gupta


#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool checkValid(ll *a,int n, int students, ll value)
{
    ll sum=0;
    int count=1;
    for(int i=0;i<n;i++)
    {
        if(sum+a[i]>value)
        {
            sum=0;
            count++;
        }
        
        if(a[i]>value)
        return false;
        
        sum+=a[i];
    }
    
    if(count<=students)
    {
        return true;
    }
    
    return false;
}


ll minimumPages(ll *a, int n, int students)
{
    ll start = 0;
    ll ans=LONG_MAX;
    ll end=0;
    
    if(n<students)
    return -1;
    
    for(int i=0;i<n;i++){
        end+=a[i];
    }
    
    while(start<=end)
    {
        ll mid = start + (end - start)/2;
        
        if(checkValid(a,n,students,mid))
        {
            ans= min(ans,mid);
            end= mid-1;
        }
        else
        {
            start = mid+1;
        }
        
    }
    return ans;
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
	    
	    ll *a = new ll[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    int students;
	    cin>>students;
	    
	    cout<<minimumPages(a,n,students)<<"\n";
	}
	
	return 0;
}