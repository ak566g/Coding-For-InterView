#include<bits/stdc++.h>
using namespace std;

vector<int>edges[100001];
bool visited[100001];
int cost[100001];

// int minCross(int n)
// {
//     cost[0]=0;
//     cost[1]=0;

//     for(int i=1;i<n;i++)
//     {
//         int v=-1;
//         for(int j=1;j<=n;j++)
//         {
//             if(visited[j]==false && (v==-1 || cost[j]<cost[v]))
//                 v=j;
//         }

//         visited[v]=true;    
        
//         for(auto it : edges[v])
//         {
//             if(visited[it]==false)
//             {
//                 if(cost[v]+1 < cost[it])
//                 {
//                     cost[it]=cost[v]+1;
//                 }
//             }
//         }
//     }
    
//     return cost[n];
// }

int minCross(int n)
{
    queue<int>q;
    q.push(1);
    cost[1]=0;
    visited[1]=true;
    while(q.size()>0)
    {
        int vertex = q.front();
        q.pop();

        for(auto i : edges[vertex])
        {
            if(visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
                cost[i]=cost[vertex]+1;
            }
        }
    }

    return cost[n];
}


int main()
{
   int t;
   cin>>t;
   
   while(t--)
   {
        for(int i=0;i<=100000;i++)
        {
            edges[i].clear();
            visited[i]=false;
            cost[i]=INT_MAX-1;
        }

        int n, m;
        cin>>n>>m;

        for(int i=0;i<m;i++)
        {
            int x, y;
            cin>>x>>y;

            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        cout<<minCross(n)<<"\n";

   }
}