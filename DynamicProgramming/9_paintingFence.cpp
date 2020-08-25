//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod= (ll)(pow(10,9))+7;

ll noOfWays(int n, int k)
{
    ll same=k;
    ll different=(k*(k-1))%mod;
    ll total=(same+different)%mod;
    
    for(int i=3;i<=n;i++){
        same=different;
        different=(total*(k-1))%mod;
        total=(same+different)%mod;
    }
    
    return total%mod;
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    cout<<noOfWays(n,k)<<"\n";
	}
	
	return 0;
}