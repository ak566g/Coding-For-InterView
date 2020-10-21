//by Ankita Gupta

#include <bits/stdc++.h>
using namespace std;

int edges[1000][1000];
bool visited[1000];
int cost[1000];

void dijkstras(int n)
{
    
    for(int i=0;i<n;i++)
        cost[i]=INT_MAX;
    
    cost[0]=0;
    
    for(int i=0;i<n-1;i++)
    {
        int v= -1;
        
        for(int j=0;j<n;j++)
        {
            if(visited[j]==false && (v==-1 || cost[j]<cost[v]))
            {
                v=j;
            }
        }
        
        visited[v]=true;
        
        for(int j=0;j<n;j++)
        {
            if(visited[j]==false && edges[v][j]!=0)
            {
                if(cost[v]+edges[v][j]<cost[j])
                    cost[j]=cost[v]+edges[v][j];
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<cost[i]<<"\n";
    }
}

int main()
{
  	int v, e;
  	cin >> v >> e;
	
    memset(edges, 0, sizeof(edges));
    memset(visited, false, sizeof(visited));
    memset(cost, 0, sizeof(cost));
    
    for(int i=0; i<e; i++)
    {
        int si, ei, w;
        cin>>si>>ei>>w;
        
        edges[si][ei]=w;
        edges[ei][si]=w;
    }
 	
	
    dijkstras(v);
    
  	return 0;
}
