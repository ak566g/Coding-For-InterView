#include <bits/stdc++.h>
using namespace std;
int edges[1001][1001];
bool visited[1001];

void dfs(int start, int n)
{
    visited[start]=true;
    
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false && edges[start][i]==1)
        {
            dfs(i, n);
        }
    }
    
}

bool isConnected(int n)
{
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            return false;
    }
    
    return true;
}


int main() {
    int V, E;
    cin >> V >> E;

    memset(edges, 0, sizeof(edges));
    memset(visited, false, sizeof(visited));
    
    for(int i=0;i<E;i++)
    {
        int si, ei;
        cin>>si>>ei;
        edges[si][ei]=1;
        edges[ei][si]=1;
    }
    
    dfs(0, V);
    
    if(isConnected(V))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    
  	return 0;
}
