//by Ankita Gupta

// 10
// 12
// 1 2
// 2 3
// 3 4
// 4 1
// 3 5
// 5 6
// 6 7
// 7 5
// 8 6
// 8 9
// 9 8
// 9 10

#include<bits/stdc++.h>
#define us unordered_set
using namespace std;

void dfs1(vector<int>edges[], int si, stack<int>&dfsOrder, us<int>&visited)
{
    visited.insert(si);
    
    for(int i=0;i<edges[si].size(); i++)
    {
        if(visited.count(edges[si][i])==0)
        {
            dfs1(edges, edges[si][i], dfsOrder, visited);
        }
    }

    dfsOrder.push(si);
}

void dfs2(vector<int>edgesT[], int si, us<int> &visited, vector<int> &components)
{
    visited.insert(si);
    components.push_back(si);
    for(int i=0;i<edgesT[si].size(); i++)
    {
        if(visited.count(edgesT[si][i])==0)
        {
            dfs2(edgesT, edgesT[si][i], visited, components);
        }
    }
}

vector<vector<int>> findScc(vector<int>edges[], vector<int>edgesT[], int n)
{
    us<int>visited;
    stack<int>dfsOrder;

    for(int i=1;i<=n;i++)
    {
        if(visited.count(i)==0)
        {
            dfs1(edges, i, dfsOrder, visited);
        }
    }

    vector<vector<int>> scc;
    visited.clear();
    while(!dfsOrder.empty())
    {
        int top = dfsOrder.top();
        dfsOrder.pop();
        vector<int>comp;
        if(visited.count(top)==0)
        {
           dfs2(edgesT, top, visited, comp);
           scc.push_back(comp);
        }
        
    }


    return scc;
}

int main(){

    int n;
    int e;

    cin>>n;
    cin>>e;
    vector<int>edges[n+1];
    vector<int>edgesT[n+1];

    for(int i=0;i<e;i++)
    {
        int x , y;
        cin>>x>>y;

        edges[x].push_back(y);
        edgesT[y].push_back(x);
    }

    vector<vector<int>> scc = findScc(edges, edgesT, n);

    for(int i=0;i<scc.size();i++)
    {
        for(int j=0;j<scc[i].size();j++)
        {
            cout<<scc[i][j]<<" ";
        }
        cout<<endl;
    }

}