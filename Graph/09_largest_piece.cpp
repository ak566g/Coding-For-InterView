//by Ankita Gupta

// Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . 
// But Gary wants the biggest piece of '1's and no '0's . 
// A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. 
// Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?

// Constraints :
// 1<=N<=50

// Input Format :
// Line 1 : An integer N denoting the size of cake 
// Next N lines : N characters denoting the cake

// Output Format :
// Size of the biggest piece of '1's and no '0's

// Sample Input :
// 2
// 11
// 01

// Sample Output :
// 3


#include<bits/stdc++.h>
#define NMAX 55
using namespace std;

bool visited[NMAX][NMAX];
char cake[NMAX][NMAX];
int d1[4]={0,0,1,-1};
int d2[4]={1,-1,0,0};

bool isValid(int i, int j, int n)
{
    return (i>=0 && j>=0 && i<n && j<n);
}

int DFS(char cake[NMAX][NMAX], int i, int j, int n)
{
    visited[i][j]=true;
    
    int ans=0;
    for(int k=0;k<4;k++)
    {
        if(isValid(i+d1[k], j+d2[k], n) && cake[i+d1[k]][j+d2[k]]=='1' && visited[i+d1[k]][j+d2[k]]==false)
        {
            ans= 1+ ans+DFS(cake, i+d1[k], j+d2[k], n);
        }
    }
    
    return ans;
}

int solve(int n,char cake[NMAX][NMAX])
{
	memset(visited,false,sizeof(visited));
    
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cake[i][j]=='1')
            {
                int temp=DFS(cake, i, j, n);
                ans=max(temp+1, ans);
            }
        }
    }
    
    return ans;
}


int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}