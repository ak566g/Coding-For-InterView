//by Ankita Gupta

// aka how many binary trees are there with n vertices
// Direct formula is (2n)!/(n! (n+1)!)


#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace std;
using boost::multiprecision::cpp_int; 
#define ll cpp_int

ll catalanNumber(int n){
    ll dp[n+1];
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=n;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            dp[i]+=(dp[j]*dp[i-j-1]);
        }
    }
    
    return dp[n];
}


int main()
 {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        cout<<catalanNumber(n)<<"\n";
    }
     
	return 0;
}