#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll kadane(int *a, int n)
{
	ll currentsum=0, maxsum=INT_MIN;
	
	for(int i=0;i<n;i++){
		currentsum+=a[i];
		
		if(currentsum>maxsum){
			maxsum=currentsum;
		}
		
		if(currentsum<0){
			currentsum=0;
		}
	}
	
	return maxsum;
}

ll kCon(int *a, int n, int k){
	
	ll prefix= INT_MIN, suffix=INT_MIN, subarray=INT_MIN, total=0;
	subarray=kadane(a,n);
	if(k==1)
	{
		return subarray;
	}
	
	ll currentsum=0;
	
	//prefix
	for(int i=0;i<n;i++){
		currentsum+=a[i];
		if(currentsum>prefix){
			prefix=currentsum;
		}
	}
	
	//total
	
	for(int i=0;i<n;i++){
		total+=a[i];
	}
	
	currentsum=0;
	//suffix
	for(int i=n-1;i>=0;i--){
		currentsum+=a[i];
		if(currentsum>suffix){
			suffix=currentsum;
		}
	}
	
	
	
	ll ans;
	
	if(total<0){
		ans= max(prefix+suffix,subarray);
	}else{
		ans= max(prefix+suffix+(total*(k-2)),subarray);
	}
	
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		
		int *a= new int[n];
		
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		cout<<kCon(a,n,k)<<endl;
	}
}
