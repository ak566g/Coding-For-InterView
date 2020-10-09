#include <bits/stdc++.h>
using namespace std;
int edges[1001][1001];
bool visited[1001];

bool hasPath(int start, int end, int n)
{
    visited[start]=true;
    if(start==end)
    {
        return true;
    }
    
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false && edges[start][i]==1)
        {
            bool temp = hasPath(i, end, n);
            if(temp)
            {
                return true;
            }
        }
    }
    
    return false;
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
    
    int start, end;
    cin>>start>>end;
    
    if(hasPath(start, end, V))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    
  	return 0;
}
