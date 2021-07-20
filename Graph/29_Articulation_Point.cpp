//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

vector<int>graph[101];
bool visited[101];
int low[101];
int in[101];
int timer;

void dfs(int node, int parent){
    visited[node]=true;
    in[node]=timer;
    low[node]=timer;
    timer++;

    int children = 0;
    
    for(auto child : graph[node]){
        if(child==parent){  // it'll be direct edge to parent, not a back edge
            continue;
        }

        if(visited[child]==true){ // this will be back edge of node, so need to update the low time of node.
            low[node] = min(low[node], in[child]);
        }else{
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if(in[node]<=low[child] && p!=-1){
               cout<<node<<" ";
            }
            children++;
        }
    }
    if(p==-1 && children > 1){
        cout<<node<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    timer=0;
    cout<<"\n";
    dfs(0, -1);
}