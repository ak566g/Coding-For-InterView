//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1000001];
bool visited[1000001];
bool inStack[1000001];
int in[1000001];
int low[1000001];
stack<int>st;
int timer = 1;
int ans = 0;
vector<int>scc;

void setArrays(){
    for(int i=0;i<=1000000;i++){
        graph[i].clear();
        in[i]=-1;
        low[i]=-1;
        visited[i]=false;
        inStack[i]=false;
    }

    timer = 1;
}

void dfs(int node){
    visited[node]=1;
    in[node]=low[node] = timer++;
    inStack[node]=true;
    st.push(node);

    for(auto child : graph[node]){
        if(visited[child] && inStack[child]){
            low[node] = min(low[node], in[child]);
        }
        else if(visited[child]==false){
            dfs(child);
            if(inStack[child])
                low[node] = min(low[node], low[child]);
        }
    }

    if(in[node]==low[node]){
        while (true)
        {
            int u = st.top();
            st.pop();
            inStack[u]=false;
            scc.push_back(u);

            if(u==node)
            break;
        }
        int s = scc.size();
        ans = max(ans, s);
        scc.clear();
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e;
    cin>>n>>e;
    
    setArrays();
    for(int i=0;i<e;i++){
        int x, y;
        cin>>x>>y;

        graph[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            dfs(i);
        }
    }

    cout<<ans;
}