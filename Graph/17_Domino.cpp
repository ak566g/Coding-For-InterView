// https://www.hackerearth.com/problem/algorithm/falling-dominos-49b1ed46/

//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
bool visited[100001];

void dfs(vector<int>edges[], int si, int n, stack<int>&st)
{
    visited[si]=true;
    for(int i=0;i<edges[si].size();i++)
    {
        if(visited[edges[si][i]]==0)
        {
            dfs(edges, edges[si][i], n, st);
        }
    }
    st.push(si);
}

void dfs1(vector<int>edges[], int si, int n)
{
    visited[si]=true;
    for(int i=0;i<edges[si].size();i++)
    {
        if(visited[edges[si][i]]==0)
        {
            dfs1(edges, edges[si][i], n);
        }
    }
}


int findCC(vector<int>edges[], int n)
{
    stack<int>st;
    memset(visited, false, sizeof(visited));
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(edges, i, n, st);
        }
    }
    
    memset(visited, false, sizeof(visited));
    while(!st.empty())
    {
        int top= st.top();
        st.pop();
        if(visited[top]==0)
        {
            dfs1(edges, top, n);
            count++;
        }
    }
    
    
    return count;
}

int main()
{
	int t;
    cin>>t;
    
    while(t--)
    {
        int v, e;
        cin>>v>>e;
        vector<int>edges[v+1];
        
        for(int i=0;i<e;i++)
        {
            int x, y;
            cin>>x>>y;
            
            edges[x].push_back(y);
        }
        
        int count=findCC(edges, v);
        cout<<count<<"\n";
    }
    
	return 0;
}
