//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>graph[100001];
bool visited[100001];

long long mod = 1000000007;

void dfs(int node, int &count){
    visited[node]=true;
    count++;

    for(auto child: graph[node]){
        if(visited[child]==false){
            dfs(child, count);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while (t--)
    {
        for(int i=0;i<=100000;i++){
            visited[i]=false;
            graph[i].clear();
        }        


        int v, e;
        cin>>v>>e;

        for(int i=0;i<e;i++){
            int x, y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int count=0;
        ll perm = 1;
        for(int i=1;i<=v;i++){
            int nodes = 0;
            if(visited[i]==false){
                count++;
                dfs(i, nodes);
                perm = (perm*nodes)%mod;
            }
        }

        cout<<count<<" "<<perm<<"\n";
    }
    
}