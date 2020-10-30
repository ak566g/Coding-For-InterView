// https://www.codechef.com/problems/FILLMTR
//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#define BLACK 1
#define WHITE 2
int visited[100001];

void dfs(int si, vector<int>components[], int color)
{
    visited[si]=color;

    for(auto i : components[si])
    {
        if(visited[i]==0)
        {
            dfs(i, components, color);
        }
    }
}

bool fillmtr()
{
    int m, n;
    memset(visited, false, sizeof(visited));
    cin>>n>>m;
    vector<int>components[n+1];
    vector< pair<int, int> >edges;
    
    //---------->Start of making Components and edges <------------//
    for(int i=0;i<m;i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        if(z==0)
        {
            components[x].push_back(y);
            components[y].push_back(x);
        }
        else {
            edges.push_back({min(x,y), max(x,y)});
        }
    }

    sort(edges.begin(), edges.end());
    //----------> Making Components and Edges till here <------------//

    for(auto i: edges)
    {
        int x = i.first;
        int y = i.second;

        if(x==y)
        {
            return false;
        }
        else if(visited[x]==0 && visited[y]==0)
        {
            dfs(x, components ,BLACK);
            if(visited[y]!=0)
            {
                return false;
            }
            dfs(y, components, WHITE);
        }
        else if(visited[x]!=0 && visited[y]!=0)
        {
            if(visited[x]==visited[y])
            {
                return false;
            }
        }
        else
        {
            if(visited[y]!=0)
            {
                swap(x, y);
            }

            if(visited[x]==WHITE)
            {
                dfs(y, components, BLACK);
            }else
            {
                dfs(y, components, WHITE);
            }
            
        }
        
    }
    return true;

}

int main(){

    int t;
    cin>>t;

    while(t--)
    {
        bool ans= fillmtr();
        if(ans)
        {
            cout<<"yes";
        }
        else
        {
            cout<<"no";
        }
        cout<<endl;
    }

}
