//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool checkValid(ll *a, int n, int c, ll distance)
{
    int cows=1;
    ll start=a[0];
    
    for(int i=1;i<n;i++){
        
        if(a[i]-start>=distance)
        {
            cows++;
            start=a[i];
        }
        
    }
    
    if(cows>=c)
        return true;
    else
        return false;
}


ll minimumDistance(ll *a, int n, int c)
{
    
    sort(a,a+n);
    
    ll start=0; 
    ll end =a[n-1]-a[0];
    
    
    ll ans = 0;
    
    while(start<=end)
    {
        ll mid = start + (end - start)/2;
        if(checkValid(a,n,c,mid))
        {
            ans= max(ans,mid);
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}


int main() {

    int t;
    cin>>t;
    
 	while(t--)
    {
        int n,c;
        cin>>n>>c;
        
        ll stalls[n];
        for(int i=0;i<n;i++)
            cin>>stalls[i];
        
        cout<<minimumDistance(stalls,n,c)<<"\n";
    }
	
}