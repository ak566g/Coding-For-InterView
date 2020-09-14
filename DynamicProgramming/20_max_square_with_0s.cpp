//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;


int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    int dp[row][col];
    memset(dp,0,sizeof(dp));
    int ans=0;
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0||j==0){
                dp[i][j]=!arr[i][j];
            }
            else if(arr[i][j]==1)
                dp[i][j]=0;
            else{
                dp[i][j]= 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
            
            if(ans<dp[i][j])
                ans=dp[i][j];
        }
    }
    
    return ans;
}

int main()
{
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}