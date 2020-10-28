#include<bits/stdc++.h>
using namespace std;

bool visited[100000];

void dfs(vector< int >graph[], int si, vector<int>&v)
{
 	visited[si]=true;
    v.push_back(si);
    
    for(int i=0;i<graph[si].size();i++)
    {
        if(visited[graph[si][i]]==false)
        {
            dfs(graph, graph[si][i], v);
        }
    }
}


int main()
{

	int t;
    cin>>t;
    
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        
        vector< int >graph[n+1];

        int p[n+1];
		int q[n+1];

        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        
        for(int i=1;i<=n;i++)
        {
            cin>>q[i];
        }
        
        for(int i=0;i<m;i++)
        {
            int ai, bi;
            cin>>ai>>bi;
            
            graph[ai].push_back(bi);
            graph[bi].push_back(ai);
        }
        
        for(int i=0;i<=n;i++)
            visited[i]=false;
        vector<vector<int> >components;
        
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==false)
            {
                vector<int>v;
                dfs(graph, i, v );
                components.push_back(v);
            }
        }
        
 
     	bool ans= true;
        for(int i=0;i<components.size();i++)
        {
     		vector<int>v1;
            vector<int>v2;
            
            for(int j=0;j<components[i].size();j++)
            {
            
                v1.push_back(p[components[i][j]]);
                v2.push_back(q[components[i][j]]);
            }
            
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            
            for(int j=0;j<v1.size();j++)
            {
                if(v1[j]!=v2[j])
                {
                    ans=false;
                    break;
                }
            }
            
            if(ans==false)
                break;
            
        }
     
        if(ans)
            cout<<"YES";
        else
            cout<<"NO";
        
        cout<<endl;
     
    }
        
        
	return 0;
}
