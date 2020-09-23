// by Ankita Gupta
// Problem Link
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

#include<bits/stdc++.h>
using namespace std;
class jobs{
    public:
    	int start;
    	int end;
    	int profit;
};

bool cmp(jobs &j1, jobs &j2)
{
    return j1.end<j2.end;
}

int lowerBound(jobs a[], int n, int value)
{
    int i=0, j=n;
    
    while(i<=j)
    {
        int mid = i + (j-i)/2;
        if(a[mid].end<=value)
        {
            if(a[mid+1].end<=value)
                i=mid+1;
            else
                return mid;
        }
        else
        {
            j=mid-1;
        }
    }
	
    return -1;
}

int main()
{
    int n;
    cin>>n;
    
    jobs a[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i].start>>a[i].end>>a[i].profit;
    }
    
    sort(a,a+n,cmp);
    
    int dp[n];
    dp[0]=a[0].profit;
    
    for(int i=1;i<n;i++)
    {
        int including = a[i].profit;
			// for(int j=i-1;j>=0;j--)
			// {
			// if(a[j].end<=a[i].start)
			// {
			// including+=dp[j];
			// break;
			// }
			// }
        
        int j=lowerBound(a,i-1,a[i].start);
        if(j!=-1){
        	including+=dp[j];
        }
        dp[i]=max(including,dp[i-1]);
    }
    
    cout<<dp[n-1];
    
    return 0;
}