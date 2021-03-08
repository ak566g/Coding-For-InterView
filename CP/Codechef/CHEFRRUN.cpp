//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>graph[100001];
vector<int>tr[100001];
int visited[100001];
int a[100001];
vector<int>order;
vector<int>scc;


void clearArrays(){
    for(int i=0;i<n;i++){
        a[i]=0;
        graph[i].clear();
        tr[i].clear();
        visited[i]=false;
    }
    order.clear();
}

void dfs1(int node){
    visited[node]=true;

    for(auto child : graph[node]){
        if(visited[child]==0){
            dfs1(child);
        }
    }

    order.push_back(node);
}

void dfs2(int node){
    visited[node]=1;

    for(auto child : tr[node]){
        if(!visited[child]){
            dfs2(child);
        }
    }
    scc.push_back(node);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        cin>>n;
        clearArrays();

        for(int i= 0;i<n;i++){
            cin>>a[i];
        }

        for(int i=1;i<=n;i++){
            int x = i-1;
            int y = (i+a[i-1])%n;
            graph[x].push_back(y);
            tr[y].push_back(x);
        }

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs1(i);
            }
        }

        // cout<<order.size();

        reverse(order.begin(), order.end());

        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        int ans = 0;
        for(auto i:order){
            if(visited[i]==false){
                scc.clear();
                dfs2(i);
                if(scc.size()==1 && scc[0]!=graph[scc[0]][0])
                continue;

                ans+=scc.size();
            }
        }
        cout<<ans<<"\n";
    }
}