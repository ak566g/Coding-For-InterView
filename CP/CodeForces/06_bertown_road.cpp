//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
vector<pair<int, int>>path;
bool vis[100001];
int in[100001];
int low[100001];
bool hasBridges;
int timer;

void dfs(int node, int parent){
    vis[node]=true;
    in[node]=timer;
    low[node]=timer;

    timer++;

    for(auto neigh: graph[node]){
        if(parent==neigh){
            continue;
        }

        if(vis[neigh]==true){
            low[node]=min(low[node], in[neigh]);

            if(in[node]>in[neigh])
                path.push_back({node, neigh});
        }else{
            dfs(neigh, node);

            path.push_back({node, neigh});
 
            if(in[node]<low[neigh]){
                hasBridges=true;
                return;
            }
            low[node]=min(low[node], low[neigh]);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    hasBridges=false;
    timer=0;
    memset(vis, false, sizeof(vis));
    dfs(1, -1);
    if(hasBridges){
        cout<<0;
    }
    else{
        for(auto p:path){
            cout<<p.first<<" "<<p.second<<"\n";
        }
    }
}