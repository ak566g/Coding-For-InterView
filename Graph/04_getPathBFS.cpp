#include <bits/stdc++.h>
using namespace std;

int edges[1001][1001];
bool visited[1001];

bool getPath(int start, int end, int n, vector<int>&path)
{
    map<int, int>pc;
    queue<int>q;
    q.push(start);
    visited[start]=true;
    
    int s=start;
    while(!q.empty())
    {
    	start = q.front();
        q.pop();
    	for(int i=0;i<n;i++)
        {
            if(visited[i]==false && edges[start][i]==1)
            {
                q.push(i);
                visited[i]=true;
                pc[i]=start;
            }
        }
    }
    
    if(visited[end]==false)
        return false;
    
    path.push_back(end);
    while(end!=s)
    {
        path.push_back(pc[end]);
        end=pc[end];
    }
    
    return true;
}

int main()
{
  	int V, E, tempX, tempY;
  	cin >> V >> E;

    memset(edges, 0, sizeof(edges));
    memset(visited, false, sizeof(false));
    
    for(int i=0;i<E;i++)
    {
        int si, ei;
        cin>>si>>ei;
        
        edges[si][ei]=1;
        edges[ei][si]=1;
    }
    
    cin>>tempX>>tempY;
    
    vector<int>path;
    
    if(getPath(tempX, tempY, V, path))
    {
        for(int i=0;i<path.size();i++)
            cout<<path[i]<<" ";
    }

  	return 0;
}
