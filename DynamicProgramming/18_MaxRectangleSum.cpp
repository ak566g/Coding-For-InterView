//by Ankita Gupta
//https://www.youtube.com/watch?v=-FgseNO-6Gk

#include <bits/stdc++.h>
using namespace std;
int matrix[101][101];

int kadanes(int a[], int n)
{
    int cursum=a[0];
    int maxsum=a[0];
    
    for(int i=1;i<n;i++){
        cursum=max(cursum+a[i],a[i]);
        maxsum=max(maxsum,cursum);
    }
    
    return maxsum;
}

int main()
{
    int m, n;
    cin>>m>>n;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    
    
    int dp[m];
    
    int l=0,r=0;
    int maxrect=matrix[0][0];
    
    for(l=0;l<n;l++)
    {	
        memset(dp,0,sizeof(dp));
        for(r=l;r<n;r++)
        {
        	for(int i=0;i<m;i++)
            {
                dp[i]+=matrix[i][r];
            }
            maxrect=max(maxrect,kadanes(dp,m));
        }
        
    }
    
    cout<<maxrect;
    
    return 0;
}
