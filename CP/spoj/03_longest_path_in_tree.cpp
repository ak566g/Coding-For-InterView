//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10001];
int visited[10001];
int maxnode, maxd;

void dfs(int node, int d){
    visited[node]=true;
    if(d>maxd){
        maxd=d;
        maxnode=node;
    }

    for (auto child: graph[node]){
        if(visited[child]==false){
            dfs(child, d+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v;
    cin>>v;

    for(int i=0;i<v-1;i++){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    maxd=-1;
    maxnode = -1;

    dfs(1, 0); 
    maxd = -1;
    for(int i=0;i<=v;i++){
        visited[i]=false;
    }
    dfs(maxnode, 0);

    cout<<maxd;     
}