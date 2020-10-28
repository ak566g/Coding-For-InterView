//by Ankita Gupta

// https://www.spoj.com/problems/BOTTOM/
// Basically the question is if you can visit one vertex to another then there must be a reverse path.
// Idea to solve is find all the strongly connected components.. and if there is outgoing edge b/w first scc to second scc then don't include first
// scc into the ans.


#include<bits/stdc++.h>
using namespace std;

bool graph[5001][5001];
bool graphT[5001][5001];
bool visited[5001];

void dfs1(int si, int n, stack<int> &st)
{
    visited[si]=true;
    
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false && graph[si][i]==1)
        {
            dfs1(i, n, st);
        }
    }
    
    st.push(si);
}

void dfs2(int si, int n, vector<int> &v)
{
    visited[si]=true;
    v.push_back(si);
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false && graphT[si][i]==1)
        {
            dfs2(i, n, v);
        }
    }
}

vector<vector<int>> findSCC(int n)
{
    stack<int>st;
    memset(visited, false, sizeof(visited));
    
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            dfs1(i, n, st);
        }
    }
    
    memset(visited, false, sizeof(visited));
    vector<vector<int>> scc;
    while(!st.empty())
    {
        int start = st.top();
        st.pop();
        
        if(visited[start]==false)
        {
            vector<int>v;
            dfs2(start, n, v);
            scc.push_back(v);
        }
    }
    
    return scc;
}


int main()
{
	int v, e;
    cin>>v;
    
    while(v!=0)
    {
        cin>>e;
        memset(graph,0,sizeof(graph));
        memset(graphT,0,sizeof(graphT));
        for(int i=0;i<e;i++)
        {
            int x, y;
            cin>>x>>y;
            graph[x][y]=1;
            graphT[y][x]=1;
        }
        
        vector<vector<int>>scc= findSCC(v);
        
//         for(int i=0;i<scc.size();i++)
//         {
//             for(int j=0;j<scc[i].size();j++)
//             {
//                 cout<<scc[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
        unordered_map<int, int>mp;
        for(int i=0;i<scc.size();i++)
        {
            for(int j=0;j<scc[i].size();j++)
            {
                mp[scc[i][j]]=i;
            }
        }
        
        
        
        vector<int>ans;
      	for(int i=0;i<scc.size();i++)
        {
            bool flag=false;
            for(int j=0;j<scc[i].size();j++)
            {
                int vertex= scc[i][j];
                for(int k=1;k<=v;k++)
                {
                    if(graph[vertex][k]==1 && mp[vertex]!=mp[k])
                    {
                        flag=true;
                        break;
                    }
                }
                
                if(flag==true)
                    break;
            }
            
            if(flag==false)
            {
                for(int k=0;k<scc[i].size();k++)
                {
                    ans.push_back(scc[i][k]);
                }
            }
        }

        
        sort(ans.begin(), ans.end());
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        
        cout<<endl;
        
        cin>>v;
    }
	return 0;
}
