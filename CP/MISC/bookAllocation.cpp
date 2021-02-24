#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool check(int *a, int s, int n , ll mid)
{
    int count=1;
    ll sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>mid)
        return false;
        
        if(sum+a[i]>mid){
            count++;
            sum=a[i];
            if(count>s)
            return false;
        }else{
            sum+=a[i];
        }
    }
    
    return true;
}


ll allocatedPages(int *a,int s, int n)
{
    if(s>n){
        return -1;
    }
    
    ll start=INT_MIN;
    ll end=0;
    
    for(int i=0;i<n;i++){
        start=max((ll)a[i],start);
        end+=a[i];
    }
    
    cout<<start<<" "<<end<<endl;
    ll ans=-1;
    
    while(start<=end){
        ll mid=start+(end-start)/2;
        
        if(check(a,s,n,mid)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
        
    }
    
    return ans;
}

int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n,s;
	    
	    //number of books
	    cin>>n;
	    int *a= new int[n];
	    
	    //pages of books
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    //number of students
	    cin>>s;
	    
	    cout<<allocatedPages(a,s,n)<<"\n";
	    
	}
	return 0;
}