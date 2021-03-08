//by Ankita Gupta

// for reference
// https://www.youtube.com/watch?v=ZeDNSeilf-Y&t=1265s

// Sample test
// 5
// 5
// 1 0
// 2 1
// 0 2
// 0 3
// 3 4

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&graph, int u, vector<int>&disc, vector<int>&low, stack<int>&st, vector<bool>&inStack){
    static int time = 0;
    disc[u]=time;
    low[u]=time;
    inStack[u]=true;
    st.push(u);
    time+=1;

    // disc == discovery time
    for(auto i:graph[u]){
        if(disc[i]==-1){
            dfs(graph, i, disc, low, st, inStack);
            low[u]=min(low[u], low[i]);
        }
        else if(inStack[i]){
            low[u]=min(low[u], disc[i]);
        }
    }

    if(low[u]==disc[u]){
        cout<<"SCC"<<"\n";

        while(st.top()!=u){
            cout<<st.top()<<" ";
            inStack[st.top()]=false;
            st.pop();
        }

        cout<<st.top()<<"\n";
        inStack[st.top()]=false;
        st.pop();
    }
}

void findSCC(vector<vector<int>>graph, int v){
    vector<int>low(v,-1);
    vector<int>disc(v,-1); // for storing discovery time
    vector<bool>inStack(v, false); // for checking if a node is in stack or not
    stack<int>st;

    for(int i=0;i<v;i++){
        if(disc[i]==-1){
            dfs(graph, i, disc, low, st, inStack);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;

    vector<vector<int>>graph(v);

    for(int i=0;i<e;i++){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
    }

    findSCC(graph, v);
}