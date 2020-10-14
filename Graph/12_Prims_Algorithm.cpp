//by Ankita Gupta


#include <bits/stdc++.h>
using namespace std;

int edge[1000][1000];
bool visited[1000];
int parent[1000];
int weight[1000];

void PRIMS(int n)
{
    for(int i=0;i<n;i++)
    {
        weight[i]=INT_MAX;
        parent[i]=-1;
        visited[i]=false;
    }
    
    parent[0]=-1;
    weight[0]=0;
    
    int count=0;
    
    while(count<n)
    {
        int v=-1;
        int w=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if((w>weight[i]||v==-1) && visited[i]==false)
            {
                v=i;
                w=weight[i];
            }
        }

        visited[v]=true;

        for(int i=0;i<n;i++)
        {
            if(edge[v][i]!=0 && weight[i]>edge[v][i] && visited[i]==false)
            {
                weight[i]=edge[v][i];
                parent[i]=v;
            }
        }
        count++;
    }
    
    
}



int main()
{
  	int V, E;
  	cin >> V >> E;
	
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            edge[i][j]=0;
        }
    }
    
    for(int i=0;i<E;i++)
    {
        int s, e, w;
        cin>>s>>e>>w;
        
        edge[s][e]=w;
        edge[e][s]=w;
    }
    
    PRIMS(V);
    
    for(int i=1;i<V;i++)
    {
        if(i<=parent[i])
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<"\n";
        }
        else
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<"\n";
        }
    }
    
  	return 0;
}
