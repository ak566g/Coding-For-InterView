// by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int *a, int n, int sum)
{
    
    // if(sum==0)
    // return true;
    
    // else if(n==0)
    // return false;
    
    // bool ans1= subsetSum(a+1,n-1,sum-a[0]);
    // bool ans2= subsetSum(a+1,n-1,sum);
    
    
    // return ans1||ans2;
    
    
    bool dp[n+1][sum+1];
    
    
    for(int i=0;i<=sum;i++){
        dp[0][i]=false;
    }
    
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    return dp[n][sum];
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
        int *a= new int[n];
        
        int sum=0;
        
        
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        
        if(sum%2==1)
        {
            cout<<"NO";
        }
        
        else if(subsetSum(a,n,sum/2))
        cout<<"YES";
        else
        cout<<"NO";
        
        cout<<endl;
    }
	
	return 0;
}