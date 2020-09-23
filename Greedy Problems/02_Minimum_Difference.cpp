//by Ankita Gupta
//Question Link
//https://practice.geeksforgeeks.org/problems/minimum-difference-pair/0

#include<bits/stdc++.h>
using namespace std;

int main() {
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
	    
	    sort(a,a+n);
	    
	    int minDiff= INT_MAX;
	    
	    for(int i=1;i<n;i++)
	    {
	        minDiff= min(minDiff, a[i]-a[i-1]);
	    }
	    
	    cout<<minDiff<<"\n";
	}
	
	return 0;
}