#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

vector<vector<pi>>graph;
vector<int>parent;
vector<int>d;
vector<bool>vis;

vector<int> dijkstras(int n){
    d[1] = 0;
    parent[1] = -1;
    
    for(int i=0;i<n;i++){
        int v = -1;
        for(int j=1;j<=n;j++){
            if(!(vis[j]) && (v==-1 || d[v]>d[j])){
                v = j;
            }
        }

        vis[v] = true;

        for(auto child : graph[v]){
            int node = child.first;
            int w = child.second;

            if(!vis[node] && d[v]+w<d[node]){
                d[node] = d[v] + w;
                parent[node] = v;
            }
        }
    }

    if(!vis[n] || d[n] == INT_MAX){
        return {-1};
    }
    
    vector<int>ans;
    int start = n;
    
    while (start!=-1){
        ans.push_back(start);
        start = parent[start];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin>>n>>e;

    graph.resize(n+3);
    parent.resize(n+3);
    d.resize(n+3);
    vis.resize(n+3);

    for(int i=0;i<=n;i++){
        d[i] = INT_MAX;
    }

    for(int i=0;i<e;i++){
        int x, y, w;
        cin>>x>>y>>w;

        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    vector<int>ans = dijkstras(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}