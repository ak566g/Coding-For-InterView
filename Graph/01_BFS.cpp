#include <bits/stdc++.h>
using namespace std;
int edges[1001][1001];
bool visited[1001];

void bfs(int start, int n)
{
    queue<int>q;
    q.push(start);
    visited[start]=true;
    
    while(!q.empty())
    {
        start= q.front();
        cout<<start<<" ";
        q.pop();
        
        for(int i=0;i<n;i++)
        {
            if(edges[start][i]==1 && visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
    
}

int main() {
    int V, E;
    cin >> V >> E;
	
    memset(edges,0,sizeof(edges));
    memset(visited,false,sizeof(visited));
    
    for(int i=0;i<E;i++)
    {
        int si, ei;
        cin>>si>>ei;
        
        edges[si][ei]=1;
        edges[ei][si]=1;
    }
	
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            bfs(i, V);
        }
    }
    
  	return 0;
}
