//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10001];
bool visited[10001];
int in[10001];
int low[10001];
bool art[10001];
int timer;

void init(){
    timer=0;
    for(int i=0;i<=10000;i++){
        graph[i].clear();
        in[i]=0;
        low[i]=0;
        visited[i]=false;
        art[i]=false;
    }
}

void dfs(int node, int parent){
    visited[node]=true;
    in[node]=timer;
    low[node]=timer;
    timer++;
    
    int children=0;
    for(auto neigh: graph[node]){
        if(parent==neigh){
            continue;
        }

        if(visited[neigh]==true){
            low[node] = min(low[node], in[neigh]);
        }
        else{
            dfs(neigh, node);
            low[node] = min(low[node], low[neigh]);

            if(low[neigh] >= in[node] && parent!=-1){
                art[node]=true;
            }
            children++;
        }
    }

    if(parent==-1 && children>1){
        art[node]=true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin>>n>>m;

    while(n!=0 && m!=0){
        init();

        for(int i=0;i<m;i++){
            int x, y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        dfs(1, -1);
        int count = 0;
        for(int i=1;i<=n;i++){
            if(art[i])
                count++;
        }
        cout<<count<<"\n";
        cin>>n>>m;
    }
}