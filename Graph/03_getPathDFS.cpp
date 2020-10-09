#include <bits/stdc++.h>
using namespace std;
int edges[1001][1001];
bool visited[1001];

bool getPath(int start, int end, int n, vector<int>&v)
{
    visited[start]=true;
    if(start==end)
    {
        v.push_back(start);
        return true;
    }
    
    for(int i=0;i<n;i++)
    {
        if(edges[start][i]==1 && visited[i]==false)
        {
            bool temp = getPath(i, end, n, v);
            if(temp)
            {
                v.push_back(start);
                return true;
            }
        }
    }
    return false;
}

int main()
{
  	int V, E, tempX, tempY;
  	cin >> V >> E;
	memset(edges,0,sizeof(edges));
    memset(visited, false, sizeof(visited));
    
    for(int i=0;i<E;i++){
        int si, ei;
        cin>>si>>ei;
        
        edges[si][ei]=1;
        edges[ei][si]=1;
    }
    
	cin>>tempX>>tempY;
    
    vector<int>v;
    
    if(getPath(tempX, tempY, V, v))
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
    }
    
    
  	return 0;
}
