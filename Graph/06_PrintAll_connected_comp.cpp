//by Ankita Gupta

#include <bits/stdc++.h>
using namespace std;
int edges[1001][1001];
bool visited[1001];

void getComponents(int start, int n, vector<int>&v)
{
    visited[start]=true;
    v.push_back(start);
    
    for(int i=0;i<n;i++)
    {
        if(edges[start][i]==1 && visited[i]==false)
        {
            getComponents(i, n, v);
        }
    }
    
    return;
}

int main()
{
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
    
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            vector<int>v;
            getComponents(i, V, v);
            sort(v.begin(), v.end());
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
    
    
    
  	return 0;
}
