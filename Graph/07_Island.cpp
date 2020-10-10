//by Ankita Gupta

// An island is a small piece of land surrounded by water . 
// A group of islands is said to be connected if we can reach from any given island to any other island in the same group . 
// Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . 
// Can you count the number of connected groups of islands.


#include<bits/stdc++.h>
using namespace std;

int edges[1001][1001];
bool visited[1001];

void dfs(int start, int n)
{
    visited[start]=true;
    
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false && edges[start][i]==1)
        {
            dfs(i, n);
        }
    }
    
    return;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	memset(edges, 0, sizeof(edges));
    memset(visited, false, sizeof(visited));
    
    for(int i=0;i<m;i++)
    {
        edges[u[i]][v[i]]=1;
        edges[v[i]][u[i]]=1;
    }
    
    int count =0;
    
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            count++;
            dfs(i, n);
        }
    }
    
    return count;
    
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}